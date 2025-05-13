#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
//     int factorial(int n) {
//     int fact = 1;
//     for (int i = 1; i <= n; i++) {
//         fact *= i;
//     }
//     return fact;
// }
  
    int nCr(int n, int r) {
        if (r > n) return 0;
        if (r > n - r) r = n - r;  // Use symmetry: C(n, r) == C(n, n - r)

        long long result = 1;

        for (int i = 1; i <= r; ++i) {
            result = result * (n - r + i) / i;
        }

        return (int)result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}