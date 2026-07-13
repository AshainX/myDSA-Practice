class Solution:
    def largestElement(self, nums):
        max = float('-inf')
        for i in nums:
            if i > max:
                max = i
        return max

if __name__ == "__main__":
    obj = Solution()
    nums = [10,20,30]
    print(obj.largestElement(nums))






# class Solution:
#     def largestElement(self, nums):
#         #return max(nums)
#         max = float('-inf')
#         for i in nums:
#             #print(i)
#             if i > max:
#                 max = i
            
#         return max