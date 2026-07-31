class Solution():
    def pattern2(self, n):
        for i in range(n):
            ## One way N^2 time complexity 
            # for j in range(i+1):
            #     print("*", end=" ")
            # print()

            ## other way N time complexity pythonic way 
            print("* " * (i+1))

           

if __name__ == "__main__":
    obj = Solution()
    n = 6
    obj.pattern2(n)