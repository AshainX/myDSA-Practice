# Given a positive integer n, find the sum of the first n natural numbers.

# Examples : 

# Input: n = 3
# Output: 6
# Explanation: 1 + 2 + 3 = 6

# Input: n = 5
# Output: 15 
# Explanation:  1 + 2 + 3 + 4 + 5 = 15

class Solutions:
    def nNaturalNums(self, n):
        # add = 0
       # n = n*(n+1)//2
        # while n > 0:
        #     add = add + n
        #     n = n-1
        return n*(n+1)//2
        #print(n)
        #print(add)

if __name__ == "__main__":
    obj = Solutions()
    n = 9
    print(obj.nNaturalNums(n))