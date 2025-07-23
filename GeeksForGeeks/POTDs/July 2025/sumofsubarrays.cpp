/*
approach 1 :
TIME COMPLEXITY : O(n^2)
SPACE COMPLEXITY : O(1)

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int size = arr.size();
        //int total =0;
        
        vector<int> pfsum(size);
        pfsum[0] = arr[0];
        for(int i = 1; i<size; i++){
            pfsum[i] = pfsum[i-1] + arr[i];
        }
       
        //return pfsum;
        // for(int i =0; i<pfsum.size(); i++){
        //     total = pfsum[i] + pfsum[i+1];
        // }
        // return total;
        
        int total = 0;
        for(int s = 0; s<size; s++){
            for(int j = s; j<size; j++){
                if(s==0){
                    total +=pfsum[j];  // 0th element from here
                }
                else{
                    total+= pfsum[j] - pfsum[s-1]; //1+elments from here
                }
            }
        }
        return total;
        
        
        
    }
};
*/

/*
TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int subArraySum(vector<int> &arr) {
        int size = arr.size();
        int sum = 0;
        for(int i = 0; i<size; i++){
            sum += arr[i]*(i+1) * (size - i);   //contribution method  
            // for example arr[0] = 1 appears in (0 + 1) * (2 - 0) = 1 * 2 = 2 subarrays → contributes 1 * 2 = 2
            //              arr[1] = 2 appears in (1 + 1) * (2 - 1) = 2 * 1 = 2 subarrays → contributes 3 * 2 = 6
        }
        
        
        return sum;
    }

int main() {
    vector<int> arr = {1, 2, 3};  // Example input
    int total = subArraySum(arr);
    cout << "Total sum of all subarrays: " << total << endl;
    return 0;
}