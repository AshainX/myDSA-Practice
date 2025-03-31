//Codeforces Round 1003 (Div. 4)
#include <bits/stdc++.h>
#include <iostream>
#include <string>
 
using namespace std;
 
string rs(string s) {
    if (s.size() >= 2 && s.substr(s.size()-2)== "us") {
        s.replace(s.size()- 2,2,"i");
    }
    return s;
}
 
int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        string s;
        cin>>s;
        cout<<rs(s)<<endl;
    }
    return 0;
}