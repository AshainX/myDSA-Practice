'''
2265. Count Nodes Equal to Average of Subtree

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
 

Example 1:


Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation: 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.
Example 2:


Input: root = [1]
Output: 1
Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.

'''


'''
The issue is: if you do it naively top-down, for node 4 you would traverse its whole subtree to get sum/count, then for node 8 you traverse its subtree again, then for node 5 again, etc. That repeats work -> O(n^2) worst case.

Better way: bottom-up, post-order.

One DFS that returns two things for each subtree:
  sum = total sum of values in that subtree
  count = total number of nodes in that subtree

Then at each node:
  total_sum = left_sum + right_sum + node.val
  total_count = left_count + right_count + 1
  avg = total_sum // total_count   integer division = round down
  if node.val == avg: answer += 1

Return sum,count upward so parent can use it.

Dry run on [4,8,5,0,1,null,6]:

  node 0: sum=0, count=1, avg=0 -> match
  node 1: sum=1, count=1, avg=1 -> match
  node 8: sum=8+0+1=9, count=3, avg=9//3=3 -> no match
  node 6: sum=6, count=1, avg=6 -> match
  node 5: sum=5+6=11, count=2, avg=11//2=5 -> match
  node 4: sum=4+9+11=24, count=6, avg=24//6=4 -> match
  total = 5

Solution:

  class Solution:
      def averageOfSubtree(self, root):
          self.res = 0

          def dfs(node):
              if not node:
                  return 0, 0
              left_sum, left_cnt = dfs(node.left)
              right_sum, right_cnt = dfs(node.right)
              total_sum = left_sum + right_sum + node.val
              total_cnt = left_cnt + right_cnt + 1
              if node.val == total_sum // total_cnt:
                  self.res += 1
              return total_sum, total_cnt

          dfs(root)
          return self.res

Time O(n), space O(h) for recursion stack, h = height.


'''



'''
APPROACH OF RECURSION:

Yes. Recursion just means function calls itself with a smaller piece. For trees the smaller piece is left child and right child.

Take this tree:

        4
      /   \
     8     5
    / \     \
   0   1     6

Call dfs(4). It cannot finish until it knows left and right. So it pauses and calls dfs(8).

Same for dfs(8). It pauses and calls dfs(0).

Stack at this point, top is what is running:

  dfs(0) <- running
  dfs(8) <- paused waiting for left
  dfs(4) <- paused waiting for left

Now step by step:

1. dfs(0):
   calls dfs(None) for left -> returns 0,0
   calls dfs(None) for right -> returns 0,0
   total = 0+0+0 = 0, count = 0+0+1 = 1
   avg = 0 // 1 = 0, node val 0 matches, count answer = 1
   returns 0,1 to its parent dfs(8)

2. dfs(8) got left result 0,1. Now it pauses again and calls right dfs(1).

3. dfs(1):
   left None -> 0,0, right None -> 0,0
   total = 1, count = 1, avg = 1 // 1 = 1, matches, answer = 2
   returns 1,1 to dfs(8)

4. dfs(8) now has both sides:
   left 0,1 and right 1,1 plus own val 8
   total = 0+1+8 = 9, count = 1+1+1 = 3
   avg = 9 // 3 = 3, node val 8 does not match
   returns 9,3 to dfs(4)

5. dfs(4) got left result 9,3. Now calls right dfs(5).

6. dfs(5) calls left dfs(None) -> 0,0, then calls right dfs(6).

7. dfs(6):
   total = 6, count = 1, avg = 6, matches, answer = 3
   returns 6,1 to dfs(5)

8. dfs(5) combines:
   left 0,0 and right 6,1 plus own val 5
   total = 0+6+5 = 11, count = 0+1+1 = 2
   avg = 11 // 2 = 5, node val 5 matches, answer = 4
   returns 11,2 to dfs(4)

9. dfs(4) now has both sides:
   left 9,3 and right 11,2 plus own val 4
   total = 9+11+4 = 24, count = 3+2+1 = 6
   avg = 24 // 6 = 4, node val 4 matches, answer = 5
   returns 24,6

Done. Answer 5.

Key idea: leaf nodes finish first because their children are None and return instantly. 
Then their parent can finish, then its parent, until root finishes last. The return values always flow upward.


'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        self.res = 0 

        def dfs(node):
            if not node:
                return 0, 0
            ls, lc = dfs(node.left)
            rs, rc = dfs(node.right)
            ts = ls + rs + node.val
            tc = lc + rc + 1
            if node.val == ts // tc:
                self.res += 1
            return ts, tc 
        
        dfs(root)
        return self.res