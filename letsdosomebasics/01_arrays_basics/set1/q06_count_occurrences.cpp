/*
 * Q06 — COUNT OCCURRENCES OF A VALUE
 *
 * Given a list of numbers and a target value, return HOW MANY TIMES
 * the target appears in the list.
 *
 * Example:
 *   a = [10, 25, 7],  target = 25  ->  1
 *   a = [3, 3, 3],    target = 3   ->  3
 *   a = [1, 2, 3],    target = 9   ->  0
 *   a = [7, 7, 1, 7], target = 7   ->  3
 */

#include <iostream>
#include <vector>
using namespace std;

int countOccurrences(const vector<int>& a, int target) {
    // YOUR CODE HERE
    return 0; // replace this
}

int main() {
    vector<vector<int>> tests = {
        {10, 25, 7},
        {3, 3, 3},
        {1, 2, 3},
        {7, 7, 1, 7}
    };
    vector<int> targets = {25, 3, 9, 7};

    for (size_t i = 0; i < tests.size(); i++) {
        cout << countOccurrences(tests[i], targets[i]) << endl;
    }

    // Expected output:
    // 1
    // 3
    // 0
    // 3
    return 0;
}
