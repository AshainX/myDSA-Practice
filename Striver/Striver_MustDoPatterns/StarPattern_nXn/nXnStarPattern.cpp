/*Geek is very fond of patterns. Once, his teacher gave him a square pattern to solve. He gave Geek an integer n and asked him to build a pattern.

Help Geek to build a square pattern with the help of *  such that each * is space-separated in each line.

Example 1:

Input:
n = 3
Output:
* * *
* * *
* * *
Example 2:

Input:
n = 5
Output:
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
Your Task: You don't need to input anything. Complete the function printSquare() which takes  an integer n  as the input parameter and print the pattern.

Time Complexity : O(n2)
Space Complexity : O(1)
*/

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
  public:
    void printSquare(int n) {
        // code here
        
        //----------- Time complexity is more ----------
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++){
        //         cout<<"*"<<" ";    
        //     }
        //     cout<<endl;
        // }
        
        //------------Efficient time complexity ---------
        string row;
        for(int i=0;i<n;i++){
            row+="* ";
        }
        row.pop_back();
        for(int i=0;i<n;i++){
            cout<<row<<endl;
        }
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printSquare(n);
    
cout << "~" << "\n";
}
    return 0;
}