/*
You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without 
changing the order of the other characters to make it equal to wordB. For example, "abc" is a predecessor of 
"abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of 
word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k = 1.

Return the length of the longest possible word chain with words chosen from the given list of words in any order.

Examples:

Input: words[] = ["ba", "b", "a", "bca", "bda", "bdca"]
Output: 4
Explanation: One of the longest word chains is ["a", "ba", "bda", "bdca"].

Input: words[] = ["abc", "a", "ab"]
Output: 3
Explanation: The longest chain is {"a", "ab" "abc"}

Input: words[] = ["abcd", "dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.

Constraint:
1 <= words.length <= 104
1 <= words[i].length <= 10
 words[i] only consists of lowercase English letters.


*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        dp.reserve(words.size()); //hashmap
        int maxLength = 1;

        for (const string &word : words) {
            int length = 1;
            for (size_t i = 0; i < word.size(); ++i) {
                string pred = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(pred)) {
                    length = max(length, dp[pred] + 1);
                }
            }
            dp[word] = length;
            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

