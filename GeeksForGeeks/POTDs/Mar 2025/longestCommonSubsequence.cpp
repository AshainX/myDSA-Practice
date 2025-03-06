/*
Given two strings s1 and s2, return the length of their longest common subsequence (LCS). 
If there is no common subsequence, return 0.

A subsequence is a sequence that can be derived from the given string by deleting some or 
no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".

Examples:

Input: s1 = "ABCDGH", s2 = "AEDFHR"
Output: 3
Explanation: The longest common subsequence of "ABCDGH" and "AEDFHR" is "ADH", which has a length of 3.

Input: s1 = "ABC", s2 = "AC"
Output: 2
Explanation: The longest common subsequence of "ABC" and "AC" is "AC", which has a length of 2.

Input: s1 = "XYZW", s2 = "XYWZ"
Output: 3
Explanation: The longest common subsequences of "XYZW" and "XYWZ" are "XYZ" and "XYW", both of length 3.

Constraints:
1<= s1.size(), s2.size() <=103
Both strings s1 and s2 contain only uppercase English letters.


*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
    int n = s1.length(), m = s2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);//1d vectors 

    for (int i = 1; i <= n; i++) {  //first string
        for (int j = 1; j <= m; j++) { //2nd string
            if (s1[i - 1] == s2[j - 1]) //if match add 1 in diagonal value
                curr[j] = 1 + prev[j - 1];
            else 
                curr[j] = max(prev[j], curr[j - 1]);//or take max from j and j-1
        }
        swap(prev, curr);//nxt row
    }

    return prev[m];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}