#include<iostream>
#include<vector>
#include<unordered_map>

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
    unordered_map<int, int> freq;  // Frequency map
    vector<pair<int, int>> result; // Result vector to store valid pairs

    // Step 1: Build frequency map
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Step 2: Find valid pairs
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int comp = target - num;

        // Case 1: When both numbers are the same (like 2 + 2 = 4)
        if (num == comp && freq[num] >= 2) {
            result.push_back({num, num});
            freq[num] -= 2;  // Decrease frequency for both occurrences
        }
        // Case 2: When both numbers exist in the frequency map
        else if (freq[num] > 0 && freq[comp] > 0) {
            result.push_back({num, comp});
            freq[num]--;
            freq[comp]--;
        }
    }

    // Step 3: If no valid pair was added
    if (result.empty()) {
        result.push_back({-1, -1});
    }

    return result;
}