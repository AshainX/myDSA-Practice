/*
 * Q09 — SWAP TWO ELEMENTS
 *
 * Given a list of numbers and two indexes i and j, swap the elements
 * at those positions (in the SAME list, modify it) and return the list.
 * Indexes are always valid (within bounds).
 *
 * Example:
 *   a = [10, 25, 7], i = 0, j = 2  ->  [7, 25, 10]
 *   a = [1, 2, 3],   i = 1, j = 1  ->  [1, 2, 3]   (same index, no change)
 *   a = [5, 6],      i = 0, j = 1  ->  [6, 5]
 *
 * In C++: a is passed by reference (&), so modify it directly and
 * you don't need to return anything. But you can still return it.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> swapElements(vector<int>& a, int i, int j) {
    // YOUR CODE HERE
    // a is passed by reference — changing it changes the original.
    return a; // leave this
}

int main() {
    vector<vector<int>> tests = {
        {10, 25, 7},
        {1, 2, 3},
        {5, 6}
    };
    vector<vector<int>> idx = {{0, 2}, {1, 1}, {0, 1}};

    for (size_t k = 0; k < tests.size(); k++) {
        vector<int> r = swapElements(tests[k], idx[k][0], idx[k][1]);
        for (int x : r) cout << x << " ";
        cout << endl;
    }

    // Expected output:
    // 7 25 10
    // 1 2 3
    // 6 5
    return 0;
}
