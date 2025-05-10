class Solution:

	def nthRowOfPascalTriangle(self, n):
	    # code here
	    ans = []
        c = 1
        ans.append(c)
        for i in range(1,n):
            c = c * (n - i) // i;
            ans.append(c)
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    tc = int(input())
    while tc > 0:
        n = int(input())
        ob = Solution()
        ans = ob.nthRowOfPascalTriangle(n)
        for x in ans:
            print(x, end=" ")
        print()
        tc = tc - 1
        print("~")