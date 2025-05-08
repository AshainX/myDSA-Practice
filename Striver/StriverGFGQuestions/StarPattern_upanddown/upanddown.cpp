#include<iostream>
using namespace std;

void nStarTriangle(int n) {
    // Write your code here.
    int flag = 0;
    for(int i=1; i<=n; i++){
        for(int j =1 ;j<=i; j++){
            cout<<"*";
        }
    flag=i;
    cout<<endl;
    }
    if(flag==n){
        for(int i=n-1;i>=1;i--){
            for(int j=i;j>0;j--){
                cout<<"*";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"*";
    }
}

int main(){
    int n;
    cin>>n;
    nStarTriangle(n);
}