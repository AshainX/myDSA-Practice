/*
Given an array of positive integers arr[] and a non-negative integer x,
the task is to find the longest sub-array where the absolute difference 
between any two elements is not greater than x.
If multiple such subarrays exist, return the one that starts at the smallest index.

Examples: 

Input: arr[] = [8, 4, 2, 6, 7], x = 4 
Output: [4, 2, 6] 
Explanation: The sub-array described by index [1..3], i.e. [4, 2, 6] contains no such difference of two elements which is greater than 4.

Input: arr[] = [15, 10, 1, 2, 4, 7, 2], x = 5 
Output: [2, 4, 7, 2] 
Explanation: The sub-array described by indexes [3..6], i.e. [2, 4, 7, 2] contains no such difference of two elements which is greater than 5. 

Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 109
0 <= x<= 109
*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   public:
//     vector<int> longestSubarray(vector<int>& arr, int x) {
//         // code here
//         //int lp = 0 , rp=0;
//         deque<int>mnd, mxd;
//         int s =0,e=0;
//         int as=0, ae=0;
//         vector<int>ans;
//         int n=arr.size();
//         while(e<n){
//             while(!mnd.empty() && arr[mnd.back()]>arr[end]) mnd.pop_back();
//             while(!mxd.empty() && arr[mxd.back()]<arr[end]) mxd.pop_back();
//             mnd.push_back(end);
//             mxd.push_back(end);
            
//             while(arr[mxd.front()]-arr[mnd.front()]>x){
//                 if(s==mxd.front()) mxd.pop_front();
//                 if(s==mnd.front()) mnd.pop_front();
//                 s++;
//             }
//             if(e-s>ae-as){
//                 ae=e;
//                 as=s;
//             }
//             e++;
//         }
//         for(int i = as; i<=ae;i++){
//             ans.push_back(arr[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> mnd, mxd; 
        int s = 0, e = 0;   
        int as = 0, ae = 0;
        int n = arr.size();

        while (e < n) {
            while (!mnd.empty() && arr[mnd.back()] > arr[e]) mnd.pop_back();
            while (!mxd.empty() && arr[mxd.back()] < arr[e]) mxd.pop_back();

            //push current
            mnd.push_back(e);
            mxd.push_back(e);

            //shrink the window when 
            while (arr[mxd.front()] - arr[mnd.front()] > x) {
                if (mxd.front() == s) mxd.pop_front();
                if (mnd.front() == s) mnd.pop_front();
                s++;
            }

            
            if (e - s + 1 > ae - as + 1) { //update longest valid subarray
                as = s;
                ae = e;
            }

            e++; //expand window accordingly
        }
        vector<int> ans; //ans subarray
        for (int i = as; i <= ae; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}