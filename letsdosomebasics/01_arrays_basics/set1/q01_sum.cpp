/*
 * Q01 — SUM OF ARRAY ELEMENTS
 *
 * Given a list of numbers, return the sum (total) of all elements.
 *
 * Example:
 *   [10, 25, 7]  ->  42   (because 10 + 25 + 7 = 42)
 *   [1, 2, 3, 4] ->  10
 *   [5]          ->  5
 *
 * Write the function body below. Do NOT change the function signature
 * or the main() test code.
 */

#include <iostream>
#include <vector>
using namespace std;

int sumArray(const vector<int>& a) {
    // YOUR CODE HERE
    // a.size() gives the number of elements

    int sum = 0;
    for (int i =0; i<a.size(); i++){
        sum+=a[i];
    }
    return sum; // replace this
}

int main() {
    vector<vector<int>> tests = {
        {10, 25, 7},
        {1, 2, 3, 4},
        {5},
        {100, 200, 300}
    };

    for (const auto& t : tests) {
        cout << sumArray(t) << endl;
    }

    // Expected output:
    // 42
    // 10
    // 5
    // 600
    return 0;
}
