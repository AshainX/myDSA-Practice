#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
	
	void printTriangle(int n) {
	    // code here
	    for(int i =1; i<=n; i++){
	        for(int j = 1;j<=i-1;j++){
	            cout<<" ";
	        }
	        for(int j=1; j<=2*(n-i+1)-1; j++){
	            cout<<"*";
	        }
	    
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