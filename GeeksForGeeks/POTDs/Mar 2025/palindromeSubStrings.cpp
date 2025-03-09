/*
Given a string s, count all palindromic sub-strings present in the string.
 The length of the palindromic sub-string must be greater than or equal to 2. 

Examples

Input: s = "abaab"
Output: 3
Explanation: All palindromic substrings are : "aba" , "aa" , "baab".

Input: s = "aaa"
Output: 3
Explanation: All palindromic substrings are : "aa", "aa", "aaa".

Input: s = "abbaeae"
Output: 4
Explanation: All palindromic substrings are : "bb" , "abba" , "aea", "eae".

Constraints:
2 ≤ s.size() ≤ 103
string contains only lowercase english characters
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
        // code here
    int expAround(const string &s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int len = right - left + 1;
            if (len >= 2) count++;  //will count substring of len max then 2
            left--;
            right++;
        }
        return count;
    }

    int countPS(string &s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += expAround(s, i, i); //odd length
            count += expAround(s, i, i + 1); //even length
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}