/*
The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

Given an integer n, find all distinct solutions to the n-queens puzzle.
You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.
For eg. below figure represents a chessboard [3 1 4 2].


Examples:

Input: n = 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.

Input: n = 4
Output: [[2 4 1 3 ] [3 1 4 2 ]]
Explaination: There are 2 possible solutions for n = 4.

Input: n = 2
Output: []
Explaination: There are no possible solutions for n = 2.


Constraints:
1 ≤ n ≤ 10

*/


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
private:
    // Function to store a valid board configuration in the answer list
    void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
        vector<int> temp;
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                if (board[row][col] == 1) {
                    temp.push_back(row + 1); // Store 1-based row index
                    break;
                }
            }
        }
        ans.push_back(temp);
    }

    // Function to check if placing a queen at (row, col) is safe
    bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
        int x = row, y = col;

        // Check the leftward row (same row, previous columns)
        while (y >= 0) {
            if (board[x][y] == 1) return false;
            y--;
        }

        // Check upper-left diagonal
        x = row, y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 1) return false;
            x--;
            y--;
        }

        // Check lower-left diagonal
        x = row, y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == 1) return false;
            x++;
            y--;
        }

        return true; // No conflicts, it's safe to place a queen here
    }

    // Recursive function to place queens column by column
    void solve(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans) {
        // If all queens are placed, add the solution and return
        if (col == n) {
            addSolution(ans, board, n);
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 1;  // Place the queen
                solve(col + 1, n, board, ans);  // Recur for next column
                board[row][col] = 0;  // Backtrack (remove the queen)
            }
        }
    }

public:
    // Function to find all solutions to the N-Queens problem
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize board with 0s
        vector<vector<int>> ans; // To store all valid board configurations
        solve(0, n, board, ans); // Start placing queens from column 0
        return ans; // Return all valid solutions
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}