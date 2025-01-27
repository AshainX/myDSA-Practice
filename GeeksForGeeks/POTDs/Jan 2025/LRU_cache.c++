/*
Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

PUT x y: sets the value of the key x with value y
GET x: gets the key of x if present else returns -1.
The LRUCache class has two methods get() and put() which are defined as follows.

get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
put(key, value): if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should remove the least recently used item before inserting the new item.
In the constructor of the class the capacity of the cache should be initialized.


Examples:

Input: cap = 2, Q = 2, Queries = [["PUT", 1, 2], ["GET", 1]]
Output: [2]
Explanation: Cache Size = 2
["PUT", 1, 2] will insert the key-value pair (1, 2) in the cache,
["GET", 1] will print the value corresponding to Key 1, ie 2.
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  
  private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator>cache;
    list<pair<int, int>> order;
    
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        capacity = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
    if (cache.find(key) != cache.end()) {
        order.splice(order.begin(), order, cache[key]);
        return cache[key]->second;
    }
    return -1;
}

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if (cache.find(key)!=cache.end()){
            cache[key]->second = value;
            order.splice(order.begin(), order, cache[key]);
            
        }
        else {
            if (order.size()== capacity){
                int lk = order.back().first;
                order.pop_back();
                cache.erase(lk);
                
            }
            
            order.push_front({key, value});
            cache[key] = order.begin();
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}