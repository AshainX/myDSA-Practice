#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string decodedString(string &s) {
        stack<int> st; // Stack to store repeat counts
        stack<string> str; // Stack to store substrings
        string curr = "";
        int n = 0;
        
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                n = n * 10 + (c - '0'); // Build the number
            } else if (c == '[') {
                st.push(n); // Push repeat count
                str.push(curr); // Push current string
                n = 0; // Reset count
                curr = ""; // Reset string
            } else if (c == ']') {
                string tmp = curr;
                int r = st.top(); st.pop();
                curr = "";
                while (r--) curr += tmp; // Repeat string
                curr = str.top() + curr; // Merge with previous
                str.pop();
            } else {
                curr += c; // Append character to current string
            }
        }
        return curr;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
        cout << "~" << "\n";
    }
    return 0;
}
