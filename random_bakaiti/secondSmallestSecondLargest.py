'''
Example 1:
Input:
 [1, 2, 4, 7, 7, 5]  
Output:
  
Second Smallest : 2  
Second Largest : 5  
Explanation:
  The elements are sorted as 1, 2, 4, 5, 7, 7.  
Hence, the second smallest element is 2, and the second largest element is 5.

Example 2:
Input:
 [1]  
Output:
  
Second Smallest : -1  
Second Largest : -1  
Explanation:
  Since there is only one element in the array, it is both the largest and smallest element.  
Therefore, there is no second smallest or second largest element present.

'''
class Solution:
    def secondSmallLarge(self, nums):
        if len(nums) < 2:
            return nums[0],-1, nums[0], -1
        small = float('inf')
        sec_small = -1
        large = float('-inf')
        sec_large = -1
        for i in range(len(nums)):
            if nums[i] < small:
                sec_small = small
                small = nums[i]
            elif nums[i] < sec_small and nums[i] > small:
                sec_small = nums[i]
            if nums[i] > large:
                sec_large = large
                large = nums[i]
            elif nums[i] > sec_large and nums[i] < large:
                sec_large = nums[i]

        # if sec_small == float('inf'):
        #     sec_small = -1
        # if sec_large == float('-inf'):
        #     sec_small = -1

        return small,sec_small, large, sec_large

if __name__ == "__main__":
    obj = Solution()
    nums = [10,20,30]
   # nums = [10,20,30,40,50,60,70,80,90]
    #nums = [1]
    print(obj.secondSmallLarge(nums))