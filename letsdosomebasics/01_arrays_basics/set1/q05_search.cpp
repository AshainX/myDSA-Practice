/*
 * Q05 — SEARCH FOR A VALUE
 *
 * Given a list of numbers and a target value, return TRUE if the
 * target appears in the list, FALSE otherwise.
 *
 * Example:
 *   a = [10, 25, 7], target = 25  ->  true
 *   a = [10, 25, 7], target = 99  ->  false
 *   a = [5],          target = 5   ->  true
 *   a = [1, 2, 3],    target = 3   ->  true
 *
 * The function returns bool (true / false).
 */

#include <iostream>
#include <vector>
using namespace std;

bool contains(const vector<int>& a, int target) {
    // YOUR CODE HERE
    return false; // replace this
}

int main() {
    vector<vector<int>> tests = {
        {10, 25, 7},
        {10, 25, 7},
        {5},
        {1, 2, 3}
    };
    vector<int> targets = {25, 99, 5, 3};

    for (size_t i = 0; i < tests.size(); i++) {
        cout << (contains(tests[i], targets[i]) ? "true" : "false") << endl;
    }

    // Expected output:
    // true
    // false
    // true
    // true
    return 0;
}
