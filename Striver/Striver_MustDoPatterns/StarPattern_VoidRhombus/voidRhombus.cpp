#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void symmetry(int n) {
    // Write your code here.

    /*
* * * * * * * * * * 
* * * *     * * * *
* * *         * * *
* *             * *
*                 *
    */
    for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"*"<<" ";
        }
        for(int k=1; k<=n-i; k++){
            cout<<"    ";
        }
        for(int k=1; k<=i; k++){
            cout<<"*"<<" ";
        }

        cout<<endl;
    }
/*
*                 *
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *
*/
    for(int i=1; i<=n; i++){
        for(int j =1; j<=i; j++){
            cout<<"*"<<" ";
        }
        for(int k =1; k<=n-i; k++){
            cout<<"    ";
        }
        for(int k=1; k<=i; k++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    symmetry(n);
}

