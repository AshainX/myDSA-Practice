#include<iostream>
#include<string>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        int size = s.size();
        bool found = false;
        
        for(int i =0 ;i<size-1; i++){
            if(s[i]==s[i+1]){
                cout<<"1"<<endl;
                found=true;
                break;
            }
            // else{
            //     continue;
            // }
        }
        if(!found){
            cout<<size<<endl;
        }
    }
return 0;
}