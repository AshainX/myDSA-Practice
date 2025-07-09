/*
Anish is teaching his brother about sub-arrays. However, his brother is sometimes very inattentive. So, he wants to test whether his brother has understood the concept 
of sub-arrays or not. He gives his brother two numbers and asks him to find the number of sub-arrays of a certain array ARR such that the maximum element of the sub-array 
lies between X and Y.

Example:-
Let, 

ARR = [2, 1, 4, 3]
X = 2 , Y = 3
Answer:- 3 (The sub-arrays which meet the requirements are [2], [2, 1], [3]).

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5
4 <= N <= 10^5
1 <= ARR[i] <= 10^9   
Time Limit: 1 sec
Sample Input 1 :
2
3 1 3
1 2 3
4 2 3
10 2 3 4
Sample Output 1 :
6
3
Explanation for Sample Output 1 :
In the first test case, the answer should be 6 because every sub-array satisfies the conditions.
In the second test case, the answer should be 3 because the sub-arrays [2], [3], and [2, 3] satisfy the conditions.
Sample Input 2 :
1
4 1 2
4 3 6 7
Sample Output 2 :
0
*/

#include <bits/stdc++.h> 
int countsub(int limit, const vector<int> &arr){
    int count = 0, len=1;
    for(int i =0; i<arr.size();++i){
        if(arr[i]<=limit){
            len++;
        }else {
            len=0;
        }
        count+=len;
    }
    return count;
}

int find(int n, vector<int> &arr, int x, int y){
    // Write your code here.  
    int at_x = countsub(y,arr);
    int at_y = countsub(x-1,arr);
    return at_x-at_y; 
    
}


/*
1️⃣ countsub(3)
We want subarrays where max ≤ 3

Initialize:

count = 0, len = 0

Loop:

i = 0 → arr[0] = 2 ≤ 3 → len = 1, count = 1

i = 1 → arr[1] = 1 ≤ 3 → len = 2, count = 3 (2 subarrays: [1], [2,1])

i = 2 → arr[2] = 4 > 3 → len = 0, no subarray here

i = 3 → arr[3] = 3 ≤ 3 → len = 1, count = 4 (subarray: [3])

👉 Final count = 4

So, 4 subarrays have max ≤ 3

2️⃣ countsub(1)
We want subarrays where max < 2

(limit = 1)

Initialize:

count = 0, len = 0

Loop:

i = 0 → arr[0] = 2 > 1 → len = 0, count = 0

i = 1 → arr[1] = 1 ≤ 1 → len = 1, count = 1

i = 2 → arr[2] = 4 > 1 → len = 0

i = 3 → arr[3] = 3 > 1 → len = 0

👉 Final count = 1

So, 1 subarray has max < 2

🧮 Final Result:
cpp
Copy
Edit
find(...) = countsub(3) - countsub(1) = 4 - 1 = 3 ✅
✅ Matches expected answer → The 3 valid subarrays are:

[2]

[2, 1]

[3]

🔑 Intuition Behind len:
The variable len counts how many valid subarrays end at index i.

Every time you get a valid element arr[i] <= limit, it can:

Start a new subarray

Be added to previous valid subarrays

E.g., if len = 3, that means:

[a, b, c]

[b, c]

[c] → 3 subarrays ending at i = c
*/