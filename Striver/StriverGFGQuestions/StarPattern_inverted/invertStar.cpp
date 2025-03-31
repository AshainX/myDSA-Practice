/*

Input: 5
Output:
* * * * *
* * * * 
* * * 
* *  
* 

*/

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
	
	void printTriangle(int n) {
	    // code here
	    int size = n;
	    for(int i=0;i<n;i++){
	        for(int j=size-1;j>=0;j--){
	            cout<<"* ";
	            
	        }
	        size--;
	        cout<<endl;
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
        ob.printTriangle(n);
    
cout << "~" << "\n";
}
    return 0;
}