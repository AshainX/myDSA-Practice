/*
 * Q04 — REVERSE THE ARRAY
 *
 * Given a list of numbers, return a NEW list with the elements in
 * reverse order. The original list must NOT be changed.
 *
 * Example:
 *   [10, 25, 7]   ->  [7, 25, 10]
 *   [1, 2, 3, 4]  ->  [4, 3, 2, 1]
 *   [5]           ->  [5]
 *
 * In C++, build a new vector<int> result, fill it in reverse, return it.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> reverseArray(const vector<int>& a) {
    // YOUR CODE HERE
    if (a.empty()) return {};
    vector<int> result;
    int n = a.size();
    for (int i = n - 1; i >= 0; i--) {
        result.push_back(a[i]);
    }
    return result; // replace this (return the new reversed vector)
}

int main() {
    vector<vector<int>> tests = {
        {10, 25, 7},
        {1, 2, 3, 4},
        {5},
        {7, 7, 7}
    };

    for (const auto& t : tests) {
        vector<int> r = reverseArray(t);
        for (int x : r) cout << x << " ";
        cout << endl;
    }

    // Expected output:
    // 7 25 10
    // 4 3 2 1
    // 5
    // 7 7 7
    return 0;
}
