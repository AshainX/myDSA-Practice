from typing import List

class Solution:
    def isRectangleOverlap(self, rec1:List[int], rec2 : List[int])-> bool:
        
        # Example 1:

        # Input: rec1 = [0, 0, 2, 2], rec2 = [1,1,3,3]
        #               x1 y1 x2 y2  where x1 and y1 is coordinate of the bottom-left corner 
        #               and x2 y2 is coordinate of its top-right corner
        #Output: true

        
        return (
            min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) and min(rec1[3], rec2[3]) > max(rec1[1], rec2[1])
        )

solution = Solution()

rec1 = [0, 0, 2, 2]
rec2 = [1, 1, 3, 3]

result = solution.isRectangleOverlap(rec1, rec2)
print(result)