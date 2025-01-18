class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        '''
        we will use two pointer technique here 
        
        
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[write_index] = nums[i]
                write_index += 1
        
        return write_index


        '''
        if not nums:
            return 0

        size = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[size] = nums[i]
                size+=1
        return size
        