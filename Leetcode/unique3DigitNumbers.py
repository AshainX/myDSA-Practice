'''
3483. Unique 3-Digit Even Numbers

You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers
that can be formed using these digits.

Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.
'''

from typing import List

# ============================================================================
# INTUITION (how to think about this problem)
# ============================================================================
# 1. We need to count DISTINCT 3-digit even numbers: 100 to 998, even only.
#    - hundreds (i) : 1-9  -> cannot be 0 (no leading zero)
#    - tens    (j) : 0-9  -> anything
#    - units   (k) : 0,2,4,6,8 -> must be even
#
# 2. Brute force thinks in INDEX space:
#    "try every i,j,k positions from digits" => n*(n-1)*(n-2) = O(n^3).
#    For n=100 that is 970k tuples + a set to de-duplicate. Correct but heavy.
#
# 3. Optimized thinks in VALUE space (combinatorics):
#    Digits are only 0-9, so there are only 10 possible values.
#    Total distinct candidates = 9 * 10 * 5 = 450 max. Always. O(1).
#    So instead of asking "which indices?", ask "which values can I form
#    with the supply I have?"
#
# 4. Two jobs, two data structures (don't mix them):
#    - SUPPLY check -> frequency array / dict / Counter.
#      Example: [0,2,2] has two 2's, so 222 needs three 2's => reject.
#    - UNIQUENESS -> NOT needed here, because we loop over distinct
#      values (i,j,k) once each. Brute force needs a set because the same
#      value triple comes from different index triples (e.g. 666).
#
# 5. Backtracking trick to check supply in O(1):
#    Decrement freq when you "use" a digit, check what's left,
#    then increment back (restore) when you are done with that branch.
#    This avoids building a Counter((i,j,k)) on every iteration.
#
# STEPS:
#   a) mp[d] = how many times digit d appears in input.
#   b) for i in 1..9: if mp[i]==0: skip, else mp[i]-=1 (use i as hundreds)
#   c)   for j in 0..9: if mp[j]==0: skip, else mp[j]-=1 (use j as tens)
#   d)     for k in 0,2,4,6,8: if mp[k]>0: valid number i*100+j*10+k
#   e)   restore mp[j]+=1, then after j-loop restore mp[i]+=1
#   f) answer = how many valid numbers found (<=450, so list/set/counter all fine)
#
# WHY FAST:
#   - Time: 450 checks max, independent of n. Brute force grows with n^3.
#   - Space: mp size 10 + answer list size <=450. Brute force stores up to ~970k tuples.
#
# ============================================================================
# DRY RUN : digits = [0, 2, 2]  (expected answer = 2 : 202, 220)
# ============================================================================
# Start: mp = [1, 0, 2, 0, 0, 0, 0, 0, 0, 0]
#         index: 0  1  2 ...
#         meaning: one '0', two '2's.
#
# --- i = 0 ---  -> skip (range starts at 1, no leading zero)
#
# --- i = 1 ---  -> mp[1]==0 -> continue (skip, no '1' in supply)
#
# --- i = 2 ---  -> mp[2]=2 >0, so USE it: mp[2] 2->1
#       mp is now [1,0,1,0,...]  (one '2' left, one '0' left)
#
#   --- j = 0 --- -> mp[0]=1 >0, so USE it: mp[0] 1->0
#         mp is now [0,0,1,0,...] (one '2' left, zero '0' left)
#
#     --- k loop (0,2,4,6,8) ---
#       k=0: mp[0]==0 -> NO (0 already used as j, none left)
#       k=2: mp[2]==1 >0 -> YES => form 2*100 + 0*10 + 2 = 202. Append.
#       k=4: mp[4]==0 -> NO
#       k=6: mp[6]==0 -> NO
#       k=8: mp[8]==0 -> NO
#     --- end k loop for j=0 => found [202] so far ---
#         RESTORE j: mp[0] 0->1
#
#   --- j = 1 --- -> mp[1]==0 -> continue
#
#   --- j = 2 --- -> mp[2]=1 >0, so USE it: mp[2] 1->0
#         mp is now [1,0,0,0,...] (one '0' left, zero '2's left)
#
#     --- k loop ---
#       k=0: mp[0]==1 >0 -> YES => form 2*100 + 2*10 + 0 = 220. Append.
#       k=2: mp[2]==0 -> NO (both 2's used as i and j, none left)
#            This is exactly why 222 is rejected: needs 3 copies, we have 2.
#       k=4,6,8: mp==0 -> NO
#     --- end k loop for j=2 => found [202, 220] so far ---
#         RESTORE j: mp[2] 0->1
#
#   --- j = 3..9 --- -> all mp==0 -> continue
#       RESTORE i: mp[2] 1->2 (back to original [1,0,2,...])
#
# --- i = 3..9 --- -> all mp==0 -> continue
#
# End: l = [202, 220] => return len(l) = 2. Matches expected output.
#
# Second dry-run check: digits = [1,2,3,4], mp=[0,1,1,1,1,0...]
#   i has 4 choices (1,2,3,4, but ...), k has 2 choices (2,4).
#   Example branch i=1 (mp[1] 1->0), j=2 (mp[2] 1->0), k loop:
#     k=2? mp[2]==0 now (used as j) -> skip, k=4? mp[4]==1 -> YES => 124.
#   Counting all such branches gives 2*3*2 = 12. Matches expected output.
# ============================================================================


class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        l = []  # stores valid distinct numbers (max 450, so list is fine)

        # mp[d] = supply count of digit d. Size 10 = O(1) space.
        mp = [0] * 10
        for d in digits:
            mp[d] += 1

        # HUNDREDS place: 1-9 only (0 would be leading zero, invalid).
        for i in range(1, 10):
            if mp[i] == 0:
                continue  # no 'i' left in supply, try next i
            else:
                mp[i] -= 1  # tentatively USE one 'i' as hundreds

            # TENS place: 0-9, anything allowed if we still have supply.
            for j in range(0, 10):
                if mp[j] == 0:
                    continue  # no 'j' left (after using i), try next j
                else:
                    mp[j] -= 1  # tentatively USE one 'j' as tens

                # UNITS place: 0,2,4,6,8 only (must be even).
                # Note: range(0, 10, 2) gives exactly [0,2,4,6,8].
                for k in range(0, 10, 2):
                    if mp[k] > 0:
                        # 'k' is still available after using i and j,
                        # so (i,j,k) respects frequency. Form the number.
                        l.append(i * 100 + j * 10 + k)
                    # else: 'k' already exhausted (e.g. trying 222 with
                    # only two 2's) -> skip, do nothing.

                mp[j] += 1  # BACKTRACK: restore 'j' for next j iteration

            mp[i] += 1  # BACKTRACK: restore 'i' for next i iteration

        return len(l)  # each (i,j,k) visited once, so already distinct
