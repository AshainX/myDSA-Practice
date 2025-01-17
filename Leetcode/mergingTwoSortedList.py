# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):

        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not list1:
            return list2
        if not list2:
            return list1
        
        if list1.val > list2.val:
            list1, list2 = list2, list1
        
        rs = list1

        while list1 and list2:
            tmp = None
            while list1 and list1.val<=list2.val:
                temp = list1
                list1 = list1.next
            
            temp.next = list2

            list1, list2 = list2, list1

        return rs
