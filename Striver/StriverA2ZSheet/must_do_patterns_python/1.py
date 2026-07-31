class Solution():
    def pattern1(self, n):
        for i in range(n):
            for j in range(n):
                print("*", end=" ")
            print()
           

if __name__ == "__main__":
    obj = Solution()
    n = 4
    print(obj.pattern1(n))