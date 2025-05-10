###### ------- SOLUTION 1 but coudnt use same space mentioned in the question ----- #######

# class Solution:
#     def pushZerosToEnd(self,arr):
#         num = []
#         zeros = []
#         for i in arr:
#             if(i==0):
#                 zeros.append(i)
#             else:
#                 num.append(i)
#         var1 = num+zeros
#         for i in range(len(arr)):
#             arr[i] = var1[i]
    
###### ------------ SOLUTION 2 which  is reccomended here --------######### 

class Solution:
    def pushZerosToEnd(self,arr):
        count = 0 
        for i in range(len(arr)):
            if (arr[i]!=0):           #checking  from the front itself from 0 to len(arr)
                arr[count] = arr[i]
                count+=1
            else:
                continue
        while(count<len(arr)):
            arr[count]=0
            count+=1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ob.pushZerosToEnd(arr)
        for x in arr:
            print(x, end=" ")
        print()
        tc -= 1
        print("~")
# } Driver Code Ends