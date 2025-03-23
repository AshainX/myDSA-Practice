/*
Factorial without Multiplication & Division
You are given a positive integer 
N
N. Your task is to compute the factorial of 
N
N without using any multiplication 
(
∗
)
(∗) or division 
(
/
)
(/) operators.

Factorial of a number 
N
N is defined as: 
N
!
=
N
×
(
N
−
1
)
×
(
N
−
2
)
×
.
.
.
×
1
N!=N×(N−1)×(N−2)×...×1.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each of the next 
T
T lines will contain a single integer 
N
N, where 
N
N is the number for which you need to calculate the factorial.
Output Format
For each test case, output the factorial of the given number 
N
N.

Constraints
1
≤
T
≤
10
1≤T≤10
0
≤
N
≤
12
0≤N≤12
*/


#include <bits/stdc++.h>
using namespace std;

int mul(int a, int b){
    int r=0;
    while(b>0){
        if(b&1){ //if last bit is set it will add a to it
            r+=a;
        }
        a=a<<1; //double a which is equivalent to a=a*2
        b=b>>1; //right shift b which is equivalent to b=b/2
    }
    return r;
}

int fact(int n){
    if(n==0||n==1) return 1;
    int f=1;
    for(int i=2; i<=n;i++){
        f=mul(f,i);
    }
    return f;
}

int main() {
	// your code goes here
	//bitwise operation 
	int t;
	cin>>t;
	while(t--){
	    int x;
	    cin>>x;
	    cout<<fact(x)<<endl;
	}
	return 0;

}