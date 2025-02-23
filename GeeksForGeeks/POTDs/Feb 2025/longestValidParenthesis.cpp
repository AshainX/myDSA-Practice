/*
Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
The closing parenthesis must be after its opening parenthesis.
Examples :

Input: s = "((()"
Output: 2
Explanation: The longest valid parenthesis substring is "()".

Input: s = ")()())"
Output: 4
Explanation: The longest valid parenthesis substring is "()()".

Input: s = "())()"
Output: 2
Explanation: The longest valid parenthesis substring is "()".

Constraints:
1 ≤ s.size() ≤ 106  
s consists of '(' and ')' only


*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        // code here big O of N
        stack<int> st;
        st.push(-1);
        int m=0;
        
        for (int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(i);
            }
            else {
                st.pop();
                
                if (st.empty()){
                    st.push(i);
                }else{
                    m=max(m,i-st.top());
                }
            }
        }
        return m;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}