#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        
        //-------------------OPTIMAL APPROACH------------------------
        int low = 0;
        int high = arr.size()-1;
        
        while(low<=high){
            int mid = (high+low)/2;
            if (mid == 0) return arr[0];
            if (mid == arr.size() - 1) return arr[arr.size() - 1];
            
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                return arr[mid];
            }
            else if(arr[mid] > arr[mid - 1]){ //decreasing
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        //--------------------BRUTE FORCE APPROACH-------------------
        // int n = arr.size();
        // for(int i =0; i<n; i++){
        //     if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
        //         return arr[i];
        //     }
        // }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}