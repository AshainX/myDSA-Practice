#include<bits/stdc++.h>
using namespace std;


vector<int> prefixSum(vector<int> &arr){
            int n = arr.size();
            vector<int> pfsum(n);
            pfsum[0] = arr[0];
            for(int i =1; i<=n; i++){
                pfsum[i] = pfsum[i-1] + arr[i];
            }
            return pfsum;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    
    vector<int> findPrefixSum = prefixSum(arr);
    for(auto i : findPrefixSum){
            cout<<i<<" ";
    }
    return 0;

}