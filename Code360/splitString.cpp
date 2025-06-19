/*
Problem statement
You are given a string ‘str’ of even length. Your task is to find out if we divide the ‘str’ from the middle, will both the substrings contain an equal number of vowels or not.

For Example:
You are given, ‘str’= ‘codingninjas’, when we split this string we get, ‘coding’ and ‘ninjas’ which both contain 2 vowels each. Hence the answer is ‘True’.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <=  10
1 <= |str| <= 10^6

‘str’ will contain upper and lower case characters of the English alphabet.
|str| is even.
Time Limit: 1 sec.
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function. 
Sample Input 1:
2
codingninjas
helloworld
Sample Output 2:
True
False
Explanation:
For the first test case, ‘str’= ‘codingninjas’, when we split this string we get, ‘coding’ and ‘ninjas’ which both contain 2 vowels each. Hence the answer is ‘True’.

For the second test case, ‘str’= ‘helloworld’, when we split this string we get ‘hello and ‘world’, which contain 2 and 1 vowels respectively. Hence the answer is ‘False’.
Sample Input 2:
2
Aa
AbbaaA
Sample Output 2:
True
False


*/





#include <bits/stdc++.h> 

bool isVow(char &str ){
    str = tolower(str);
    if(str=='a'||str=='e'||str=='i'||str=='o'||str=='u'){
        return true;
    }
    return false;
}

bool splitString(string &str){
    // Write your code here.
    int countLeft = 0, countRight = 0;
    int mid = str.size()/2;
    for(int i = 0; i<mid; i++){
        if(isVow(str[i])){
            countLeft++;
        }
    }
    for(int i = mid; i<str.size(); i++){
        if(isVow(str[i])){
            countRight++;
        }
    }    
    
    // if(countRight==countLeft){
    //     return true;
    // }
    // else{
    //     return false;
    // }
    return countRight==countLeft;    //something new i learnt

}