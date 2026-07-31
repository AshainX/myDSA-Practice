class Solution():
    def pattern3(self, n):

##################### MY SOLUTION ###########################
        # for i in range(n):
        #     var = 1
        #     for j in range(i+1):
        #         print(var, end=" ")
        #         var+=1
        #     print()

#################### Theirs Solution #########################
        for i in range(1, n+1):
            for j in range(1, i+1):
                print(j, end=" ")
            print()

           

if __name__ == "__main__":
    obj = Solution()
    n = 6
    obj.pattern3(n)