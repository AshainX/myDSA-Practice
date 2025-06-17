#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        
        //BRUTE FORCE
        // int count = 0;
        // int n = s.size();
        
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(s[i]==s[j]){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
        
        
        //OPTIMISED
        vector<int> f(26,0);
        int len = s.size();
        for(int i = 0; i<len; i++){
            f[s[i]-'a']++;
        }
        int count = 0;
        for(int i=0; i<26;i++){
            count+=(f[i]*(f[i]+1))/2;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}