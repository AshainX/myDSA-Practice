#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void getStarPattern(int n) {
    // Write your code here.
    // for(int i = 1; i<=n; i++){
    //     if(i==1||i==n){
    //         for(int i=1;i<=n; i++){
    //             cout<<"*";
    //         }
    //         cout<<endl;
    //     }
    //     else{
    //         for(int j=1; j<=1; j++){
    //             cout<<"*";
    //         }
    //         for(int k=1; k<=n-i ; k++){
    //             cout<<"  ";
    //         }
    //         for(int j=1; j<=1; j++){
    //             cout<<"*";
    //         }
    //         cout<<endl;
    //     }
    // }


    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if( i==1||i==n||j==1||j==n){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}


int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    getStarPattern(n);
    return 0;
}