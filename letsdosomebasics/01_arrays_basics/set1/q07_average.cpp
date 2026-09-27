/*
 * Q07 — AVERAGE OF ARRAY
 *
 * Given a list of numbers, return the average (mean) of all elements
 * as a double. Average = (sum of all elements) / (number of elements).
 * The list will always have at least one element.
 *
 * Example:
 *   [10, 25, 7]   ->  14.0   (42 / 3)
 *   [1, 2, 3, 4]  ->  2.5    (10 / 4)
 *   [5]           ->  5.0
 *
 * HINT: careful with division in C++ — dividing an int by an int
 * gives an int. Make at least one of them a double.
 */

#include <iostream>
#include <vector>
using namespace std;

double average(const vector<int>& a) {
    // YOUR CODE HERE
    return 0.0; // replace this
}

int main() {
    vector<vector<int>> tests = {
        {10, 25, 7},
        {1, 2, 3, 4},
        {5},
        {0, 0, 0}
    };

    for (const auto& t : tests) {
        cout << average(t) << endl;
    }

    // Expected output:
    // 14
    // 2.5
    // 5
    // 0
    return 0;
}
