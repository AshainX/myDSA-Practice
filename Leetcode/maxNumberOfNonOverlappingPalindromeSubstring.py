'''
2472. Maximum Number of Non-overlapping Palindrome Substrings

Hard

You are given a string s and a positive integer k.

Select a set of non-overlapping substrings from the string s that satisfy the following conditions:

The length of each substring is at least k.
Each substring is a palindrome.
Return the maximum number of substrings in an optimal selection.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abaccdbbd", k = 3
Output: 2
Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
It can be shown that we cannot find a selection with more than two valid substrings.
Example 2:

Input: s = "adbcda", k = 2
Output: 0
Explanation: There is no palindrome substring of length at least 2 in the string.

'''


class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)
        if k == 1:
            return n

        count = 0
        i = 0

        while i <= n - k:
            found_palindrome = False

            # Check for a minimal palindrome of length k or k + 1
            for length in (k, k + 1):
                # 1. Make sure we don't go past the end of string s
                if i + length <= n:
                    # 2. Grab the slice of size `length`
                    sub = s[i : i + length]

                    # 3. Check if it reads the same forwards and backwards
                    if sub == sub[::-1]:
                        count += 1
                        i += length  # Jump past this whole palindrome
                        found_palindrome = True
                        break  # Stop checking length k + 1, move on

            # If no palindrome started at index i, shift forward by 1
            if not found_palindrome:
                i += 1

        return count