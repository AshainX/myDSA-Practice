/*

*/
// /*-----------------------------------------------------------------------*/
// // 1st code that was brute force and time complexity was high 

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//   public:
//     vector<int> maxOfMins(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> result;

//         // Iterate over all possible window sizes from 1 to n
//         for (int k = 1; k <= n; k++) {
//             int maxMin = INT_MIN; // Stores the max of all minimums for window size k

//             // Slide the window of size k across the array
//             for (int i = 0; i <= n - k; i++) {
//                 int minVal = INT_MAX; // To find the minimum in this window

//                 // Find the minimum in the current window
//                 for (int j = i; j < i + k; j++) {
//                     minVal = min(minVal, arr[j]);
//                 }

//                 // Update the maximum of minimums
//                 maxMin = max(maxMin, minVal);
//             }

//             // Store the answer for window size k
//             result.push_back(maxMin);
//         }
//         return result;
//     }
// };

// // Driver Code
// int main() {
//     int t;
//     cin >> t;
//     cin.ignore();
//     while (t--) {
//         string line;
//         getline(cin, line);
//         stringstream ss(line);
//         vector<int> arr;
//         int num;
//         while (ss >> num) {
//             arr.push_back(num);
//         }
//         Solution ob;
//         vector<int> res = ob.maxOfMins(arr);
//         for (int i : res)
//             cout << i << " ";
//         cout << endl;
//     }
//     return 0;
// }
// /*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// // 2nd code that was optimized and time complexity was reduced to N^2 using Deque

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//   public:
//     vector<int> maxOfMins(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> result(n, INT_MIN);

//         // Iterate over all possible window sizes
//         for (int k = 1; k <= n; k++) {
//             deque<int> dq;
//             int maxMin = INT_MIN;

//             // Process the first window of size k
//             for (int i = 0; i < k; i++) {
//                 while (!dq.empty() && arr[dq.back()] >= arr[i])
//                     dq.pop_back();
//                 dq.push_back(i);
//             }
//             maxMin = max(maxMin, arr[dq.front()]);

//             // Slide the window across the array
//             for (int i = k; i < n; i++) {
//                 // Remove elements that are out of this window
//                 while (!dq.empty() && dq.front() <= i - k)
//                     dq.pop_front();

//                 // Remove elements from back that are not useful
//                 while (!dq.empty() && arr[dq.back()] >= arr[i])
//                     dq.pop_back();

//                 // Insert new element at the back
//                 dq.push_back(i);

//                 // The minimum element of this window is at the front
//                 maxMin = max(maxMin, arr[dq.front()]);
//             }

//             // Store the max of minimums for this window size
//             result[k - 1] = maxMin;
//         }
//         return result;
//     }
// };

// // Driver Code
// int main() {
//     int t;
//     cin >> t;
//     cin.ignore();
//     while (t--) {
//         string line;
//         getline(cin, line);
//         stringstream ss(line);
//         vector<int> arr;
//         int num;
//         while (ss >> num) {
//             arr.push_back(num);
//         }
//         Solution ob;
//         vector<int> res = ob.maxOfMins(arr);
//         for (int i : res)
//             cout << i << " ";
//         cout << endl;
//     }
//     return 0;
// }
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// 3rd code that was optimized and time complexity was reduced O(N) complexity 

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> s;

        // Compute previous smaller elements
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty()) left[i] = s.top();
            s.push(i);
        }

        // Clear the stack for next computation
        while (!s.empty()) s.pop();

        // Compute next smaller elements
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty()) right[i] = s.top();
            s.push(i);
        }

        // Create result array
        vector<int> ans(n, 0);
        vector<int> window(n + 1, INT_MIN);

        // Fill window array
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            window[len] = max(window[len], arr[i]);
        }

        // Fill remaining values in window array
        for (int i = n - 1; i >= 1; i--) {
            window[i] = max(window[i], window[i + 1]);
        }

        // Copy result from window array
        for (int i = 1; i <= n; i++) {
            ans[i - 1] = window[i];
        }

        return ans;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
