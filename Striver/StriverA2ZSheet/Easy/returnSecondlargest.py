# Second Largest Element

# Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.
# Example 1
# Input: nums = [8, 8, 7, 6, 5]
# Output: 7
# Explanation:
# The largest value in nums is 8, the second largest is 7

# Example 2
# Input: nums = [10, 10, 10, 10, 10]
# Output: -1
# Explanation:
# The only value in nums is 10, so there is no second largest value, thus -1 is returned

class Solution:
    def secondLargestElement(self, nums):
        flarge = float('-inf')
        slarge = float('-inf')
        for i in range(len(nums)):
            if nums[i] > flarge:
                slarge = flarge
                flarge = nums[i]
            elif nums[i] > slarge and nums[i] != flarge:
                slarge = nums[i]
                #flarge = nums[i]
        if slarge == float('-inf'):
            return -1 
        else:
            return slarge
        #print(slarge)

if __name__ == "__main__":
    obj = Solution()
    #nums = [8, 8, 7, 6, 5]
    nums = [10,20,30,40,50,60,70,80,90]
    #nums = [1]
    print(obj.secondLargestElement(nums))