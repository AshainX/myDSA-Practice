'''
Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.

'''

class Solution:
    
    def isSafe(self, mat, row, col, num):
        for i in range(9):
            if mat[row][i] == num:
                return False
        
        for i in range(9):
            if mat[i][col] == num:
                return False
        
        startRow = row - row % 3
        startCol = col - col % 3
        for i in range(3):
            for j in range(3):
                if mat[i + startRow][j + startCol] == num:
                    return False
        
        return True

    def sudoku(self, mat):
        for row in range(9):
            for col in range(9):
                if mat[row][col] == 0:
                    for num in range(1, 10):
                        if self.isSafe(mat, row, col, num):
                            mat[row][col] = num
                            if self.sudoku(mat):
                                return True
                            mat[row][col] = 0
                    return False
        return True

    def solveSudoku(self, mat):
        self.sudoku(mat)
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    index = 1

    for _ in range(t):
        matrix = []
        n = 9
        for i in range(n):
            row = list(map(int, data[index:index + n]))
            matrix.append(row)
            index += n
        obj = Solution()
        obj.solveSudoku(matrix)
        for i in range(n):
            for j in range(n):
                print(matrix[i][j], end=" ")
            print()
        print("~")