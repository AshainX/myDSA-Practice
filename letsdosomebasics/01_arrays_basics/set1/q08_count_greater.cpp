/*
 * Q08 — COUNT NUMBERS GREATER THAN A VALUE
 *
 * Given a list of numbers and a value `threshold`, return how many
 * elements are STRICTLY GREATER than `threshold`.
 *
 * Example:
 *   a = [10, 25, 7], threshold = 9   ->  2   (10 and 25)
 *   a = [5, 5, 5],   threshold = 5   ->  0   (equal is NOT greater)
 *   a = [1, 2, 3],   threshold = 0   ->  3
 *   a = [8],         threshold = 100 ->  0
 */

#include <iostream>
#include <vector>
using namespace std;

int countGreater(const vector<int>& a, int threshold) {
    // YOUR CODE HERE
    int count = 0;
    for(int i = 0; i<a.size(); i++){
        if (a[i]>threshold){
            count++;
        }
    }
    return count; // replace this
}

int main() {
    vector<vector<int>> tests = {
        {10, 25, 7},
        {5, 5, 5},
        {1, 2, 3},
        {8}
    };
    vector<int> thresholds = {9, 5, 0, 100};

    for (size_t i = 0; i < tests.size(); i++) {
        cout << countGreater(tests[i], thresholds[i]) << endl;
    }

    // Expected output:
    // 2
    // 0
    // 3
    // 0
    return 0;
}
