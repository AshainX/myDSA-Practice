#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;


int main(){
    unordered_set<int> s;
    unordered_set<string> str;

    s.insert(1);
    s.insert(2);

    cout<<s.count(2)<<endl; // returns 1, since 2 is present
    cout<<s.count(3)<<endl; // returns 0, since 3 is not present
    cout<< "Size of set: " << s.size() << endl; // returns 2
    cout<< "Is set empty? " << s.empty() << endl; // returns 0 (false)
    cout<< "Elements in set: ";
    for (auto& elem : s) {
        cout << elem << " ";
    }
    return 0;

}
