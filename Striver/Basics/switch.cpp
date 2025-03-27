//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int t = -1;
    cout<<"Enter Some number from 0-1 : ";
    // cin>>t;

    if(!(cin>>t)){
        cout<<"Invalid Input"<<endl;
        return 1;
    }

    switch(t){
        case 0:
            cout<<"Its zero "<<endl; 
            break;
        case 1:
            cout<<"Its one"<<endl;
            break;
        default:
            cout<<"try to press 1 or 0 only lol "<<endl;
            break;
    }

    return 0;
}