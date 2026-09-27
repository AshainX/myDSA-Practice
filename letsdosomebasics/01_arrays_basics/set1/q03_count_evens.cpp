/*
 * Q03 — COUNT EVEN NUMBERS
 *
 * Given a list of numbers, return how many of them are EVEN.
 * (An even number is divisible by 2, i.e. number % 2 == 0.)
 *
 * Example:
 *   [10, 25, 7]   ->  1   (only 10 is even)
 *   [2, 4, 6]     ->  3
 *   [1, 3, 5]     ->  0
 *   [0, 8, 3]     ->  2
 */

#include <iostream>
#include <vector>
using namespace std;

int countEvens(const vector<int>& a) {
    // YOUR CODE HERE
    if (a.size() == 0) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }   
    return count; // replace this
}

int main() {
    vector<vector<int>> tests = {
        {10, 25, 7},
        {2, 4, 6},
        {1, 3, 5},
        {0, 8, 3}
    };

    for (const auto& t : tests) {
        cout << countEvens(t) << endl;
    }

    // Expected output:
    // 1
    // 3
    // 0
    // 2
    return 0;
}
