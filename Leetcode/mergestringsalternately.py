'''
1768. Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.
return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d


'''

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        res = []
        i = 0
        
        while i<len(word1) and i<len(word2):
            res.append(word1[i])
            res.append(word2[i])
            i+=1

        j = i
        if len(word1) != 0:
            while j < len(word1):
                res.append(word1[j])
                j+=1
        j = i
        if len(word2) != 0:
            while j < len(word2):
                res.append(word2[j])
                j+=1
        

        # for wd1 in word1:
            # string.append(wd1)
            # for wd2 in word2:
                # string.append(wd2)
                # break
        return "".join(res)

