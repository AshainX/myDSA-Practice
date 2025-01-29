/*
Implement the function power(b, e), which calculates b raised to the 
power of e (i.e. be).

Examples:

Input: b = 3.00000, e = 5
Output: 243.00000

Input: b = 0.55000, e = 3
Output: 0.16638
I
nput: b = -0.67000, e = -7
Output: -16.49971


Constraints:

-100.0 < b < 100.0
-109 <= e <= 109
Either b is not zero or e > 0.
-104 <= be <= 104

*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    double power(double b, int e) {
        if (e == 0) return 1.0;  // Base case: anything raised to 0 is 1

        //for negative exponent, calculate power for positive exponent and take reciprocal
        if (e < 0) {
            b = 1.0 / b;
            e = -e;  //exp positive fr calc
        }

        double result = 1.0;
        while (e > 0) {
            if (e % 2 == 1) {  //if exp is odd
                result *= b;
            }
            b *= b;  
            e /= 2; 
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}