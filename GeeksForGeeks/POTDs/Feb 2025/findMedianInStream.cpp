/*
Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.

Examples:

Input:  arr[] = [5, 15, 1, 3, 2, 8]
Output: [5.0, 10.0, 5.0, 4.0, 3.0, 4.0] 
Explanation: 
After reading 1st element of stream – 5 -> median = 5.0
After reading 2nd element of stream – 5, 15 -> median = (5+15)/2 = 10.0 
After reading 3rd element of stream – 5, 15, 1 -> median = 5.0
After reading 4th element of stream – 5, 15, 1, 3 ->  median = (3+5)/2 = 4.0
After reading 5th element of stream – 5, 15, 1, 3, 2 -> median = 3.0
After reading 6th element of stream – 5, 15, 1, 3, 2, 8 ->  median = (3+5)/2 = 4.0


Input: arr[] = [2, 2, 2, 2]
Output: [2.0, 2.0, 2.0, 2.0]
Explanation: 
After reading 1st element of stream – 2 -> median = 2.0
After reading 2nd element of stream – 2, 2 -> median = (2+2)/2 = 2.0
After reading 3rd element of stream – 2, 2, 2 -> median = 2.0
After reading 4th element of stream – 2, 2, 2, 2 ->  median = (2+2)/2 = 2.0

Constraints:
1 <= arr.size() <= 105
1 <= x <= 106

*/


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        //make two heap low and high and play with it by shifting 
        
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;
        
        vector<double> med;
        
        for(int num:arr){
            maxheap.push(num);
        
        if(!maxheap.empty()&& !minheap.empty() && maxheap.top()>minheap.top()){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        
        if(maxheap.size()>minheap.size()+1){ //agar maxheap mei jyada hai toh minheap se pop krke max heapmei dalenge
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size()>maxheap.size()){ //same waise hi bs ulta 
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
        if(maxheap.size()>minheap.size()){ //median store n or n/2 acc to odd or even 
            med.push_back(maxheap.top());
            
        }else{
            med.push_back((maxheap.top() +minheap.top())/2.0);  //forgot my floating point value
        }
        
    }
    return med;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}