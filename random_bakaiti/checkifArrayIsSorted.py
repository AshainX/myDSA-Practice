class Solution:
    def isArraySorted(self, arr):
        flag = True
        for i in range(len(arr) -1):
            if arr[i] > arr[i+1]:
                flag = False
        return flag


if __name__ == '__main__':
    obj = Solution()
   # arr = [23,54,33,5,23,6,7,53]
    arr = [1,2,3,4,5,6,7,8,9]
    print(obj.isArraySorted(arr))






































    # class Solution:
#     def isArraySorted(self, arr):
#         flag = True
#         for i in range(len(arr)-1):
#             if arr[i] > arr[i+1]:
#                 flag = False
#         return flag
