/*
Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.

Examples:

Input: s1 = "geek", s2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e' in s1.

Input: s1 = "gfg", s2 = "gfg"
Output: 0
Explanation: Both strings are same.

Input: s1 = "abcd", s2 = "bcfe"
Output: 3
Explanation: We can convert s1 into s2 by removing ‘a’, replacing ‘d’ with ‘f’ and inserting ‘e’ at the end. 

Constraints:
1 ≤ s1.length(), s2.length() ≤ 103

*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
    int m = s1.size();
    int n = s2.size();
    int prev; 
    vector<int> curr(n + 1, 0); 
    for (int j = 0; j <= n; j++)
        curr[j] = j;
    for (int i = 1; i <= m; i++) {
        prev = curr[0]; 
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            int temp = curr[j];
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev;
            else
                curr[j] = 1 + min({curr[j - 1], prev, curr[j]});
            prev = temp;
        }
    }
    
    return curr[n];
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}