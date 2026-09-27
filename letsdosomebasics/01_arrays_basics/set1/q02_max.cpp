/*
 * Q02 — FIND THE MAXIMUM ELEMENT
 *
 * Given a list of numbers, return the largest value in the list.
 * The list will always have at least one element.
 *
 * Example:
 *   [10, 25, 7]   ->  25
 *   [1, 2, 3, 4]  ->  4
 *   [5]           ->  5
 *   [9, 9, 9]     ->  9
 *
 * Hint: start your "max" with the FIRST element, not 0.
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxElement(const vector<int>& a) {
    // YOUR CODE HERE
    long long int m = INT_MIN;
    for (int i =0; i< a.size(); i++){
        if(a[i]> m){
            m = a[i];
        }
    }
    return m; // replace this
}

int main() {
    vector<vector<int>> tests = {
        {10, 25, 7},
        {1, 2, 3, 4},
        {5},
        {9, 9, 9},
        {-3, -1, -7}
    };

    for (const auto& t : tests) {
        cout << maxElement(t) << endl;
    }

    // Expected output:
    // 25
    // 4
    // 5
    // 9
    // -1
    return 0;
}
