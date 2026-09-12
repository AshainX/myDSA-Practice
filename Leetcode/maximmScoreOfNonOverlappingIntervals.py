'''
3414. Maximum Score of Non-overlapping Intervals
Hard

You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. Interval i starts at position li and ends at ri, and has a weight of weighti. You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is defined as the total sum of their weights.

Return the lexicographically smallest array of at most 4 indices from intervals with maximum score, representing your choice of non-overlapping intervals.

Two intervals are said to be non-overlapping if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.

 

Example 1:

Input: intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]

Output: [2,3]

Explanation:

You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3.

Example 2:

Input: intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]]

Output: [1,3,5,6]

Explanation:

You can choose the intervals with indices 1, 3, 5, and 6 with respective weights of 7, 6, 3, and 5.

'''

# ============================================================================
# TOP-DOWN (recursion + memo) SOLUTION
# ============================================================================
#
# THE DP IDEA (the part that matters, same in any style):
#
#   State:      solve(i, k) = best (score, indices) using intervals from the
#                             sorted order [0..i] while allowed to pick k more.
#   Transition: at interval i we have TWO choices:
#                 skip -> solve(i-1, k)
#                 take -> weight + solve(j, k-1)   (j = last non-overlapping)
#   Base case:  i < 0 or k == 0 -> (0, [])
#
#   Because "take" jumps backward to j (a smaller i), the recursion always
#   shrinks, so it terminates. A memo stops us from recomputing the same
#   (i, k) twice.
#
# ----------------------------------------------------------------------------

from bisect import bisect_left
from functools import lru_cache


def maximumScore(intervals):
    n = len(intervals)

    # Keep original index so we can return it in the answer.
    # Sort by END time -- standard trick for non-overlapping interval problems.
    items = sorted(range(n), key=lambda i: intervals[i][1])

    starts = [intervals[idx][0] for idx in items]
    ends = [intervals[idx][1] for idx in items]
    weights = [intervals[idx][2] for idx in items]

    # compat[i] = index of the LAST interval (in sorted order) that ends
    # strictly before interval i starts. -1 if none exists.
    # We binary search: we want end[j] < start[i].
    compat = [0] * n
    for i in range(n):
        # bisect_left finds the first position where ends[pos] >= starts[i].
        # The element just before that has end < start, so it's compatible.
        compat[i] = bisect_left(ends, starts[i]) - 1

    # Returns (best_score, best_index_list) for the subproblem:
    #   "consider intervals 0..i, may still pick up to k of them".
    @lru_cache(maxsize=None)
    def solve(i, k):
        # Base case: nothing left to consider, or no picks allowed.
        if i < 0 or k == 0:
            return (0, ())

        # Choice 1: skip interval i.
        skip = solve(i - 1, k)

        # Choice 2: take interval i, then jump to the last non-overlapping one.
        sub_score, sub_idxs = solve(compat[i], k - 1)
        take_score = weights[i] + sub_score
        # Store this interval's ORIGINAL index (items[i]), not the sorted pos.
        take = (take_score, tuple(sorted((items[i],) + sub_idxs)))

        # Decide between skip and take.
        if take[0] > skip[0]:
            return take
        if skip[0] > take[0]:
            return skip
        # Tie on score -> lexicographically smaller index list wins.
        return take if take[1] < skip[1] else skip

    _, best_indices = solve(n - 1, 4)
    return list(best_indices)


# ============================================================================
# BOTTOM-UP (loops + table) SOLUTION
# ============================================================================
#
# Same state, same transition, just filled in the opposite direction.
#
#   dp[i][k] = best (score, indices) using sorted positions 0..i with <= k picks
#
# We fill i from 0 upward. For each cell:
#   skip = dp[i-1][k]
#   take = w[i] + dp[compat[i]][k-1]
#
# Extra row trick: we index dp with i from 1..n, where dp[i] means "first i
# intervals" (positions 0..i-1). This cleanly handles the empty/base case as
# dp[0][k] = (0, ()), so we never have to special-case i = -1 or compat = -1.
# ----------------------------------------------------------------------------


def maximumScoreBottomUp(intervals):
    n = len(intervals)

    items = sorted(range(n), key=lambda i: intervals[i][1])
    starts = [intervals[idx][0] for idx in items]
    ends = [intervals[idx][1] for idx in items]
    weights = [intervals[idx][2] for idx in items]

    # compat[i] = last SORTED POSITION that ends before interval i starts, or -1.
    compat = [bisect_left(ends, starts[i]) - 1 for i in range(n)]

    # dp[i][k]: first i intervals, up to k picks.
    # Dimensions: (n+1) rows, 5 columns (k = 0..4).
    dp = [[(0, ())] * 5 for _ in range(n + 1)]

    # Fill row by row. Row 0 is already the base case (no intervals -> score 0).
    for i in range(1, n + 1):
        pos = i - 1  # sorted position of the interval we are deciding on
        for k in range(1, 5):
            # Skip interval `pos`.
            skip = dp[i - 1][k]

            # Take interval `pos`: add weight, then use row (compat[pos] + 1).
            # compat[pos] = -1 means "no compatible interval" -> row 0.
            prev = dp[compat[pos] + 1][k - 1]
            take = (weights[pos] + prev[0],
                    tuple(sorted((items[pos],) + prev[1])))

            # Pick winner; on a score tie prefer the lexicographically smaller.
            if take[0] > skip[0]:
                dp[i][k] = take
            elif skip[0] > take[0]:
                dp[i][k] = skip
            else:
                dp[i][k] = take if take[1] < skip[1] else skip

    return list(dp[n][4][1])


# ----------------------------- Try it out -----------------------------------
if __name__ == "__main__":
    tests = [
        ([[1, 3, 2], [4, 5, 2], [1, 5, 5],
          [6, 9, 3], [6, 7, 1], [8, 9, 1]], [2, 3]),
        ([[5, 8, 1], [6, 7, 7], [4, 7, 3], [9, 10, 6],
          [7, 8, 2], [11, 14, 3], [3, 5, 5]], [1, 3, 5, 6]),
    ]
    for data, expected in tests:
        top = maximumScore(data)
        bottom = maximumScoreBottomUp(data)
        print("top-down  :", top, "| bottom-up:", bottom, "| expected:", expected)