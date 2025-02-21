/*
Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', verify the validity of the arrangement.
An input string is valid if:

         1. Open brackets must be closed by the same type of brackets.
         2. Open brackets must be closed in the correct order.

Examples :

Input: s = "[{()}]"
Output: true
Explanation: All the brackets are well-formed.

Input: s = "[()()]{}"
Output: true
Explanation: All the brackets are well-formed.

Input: s = "([]"
Output: False
Explanation: The expression is not balanced as there is a missing ')' at the end.

Input: s = "([{]})"
Output: False
Explanation: The expression is not balanced as there is a closing ']' before the closing '}'.

Constraints:
1 ≤ s.size() ≤ 106
s[i] ∈ {'{', '}', '(', ')', '[', ']'}
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        for (char c:s) {
            if (c=='('||c=='{'||c=='['){
                st.push(c);
            }
        else if (c==')'||c=='}'||c==']'){
         if(st.empty()) return false;   
         
         char t = st.top();
         st.pop();
        //  if ((c=='(')&&(t==')')||(c=='{')&&(t=='}')||(c=='[')&&(t==']')){
        //      return true;
        //  }
         if((c==')')&&(t!='(')||(c=='}')&&(t!='{')||(c==']')&&(t!='[')){
             return false;
         }
        //  else return false;
        }
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}