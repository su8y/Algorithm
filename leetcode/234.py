''' 234. Palindrome Linked List  '''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # convert to array: T, S: O(N), O(N)
    def isPalindrome(self, head: Optional[ListNode]) -> bool:

        # first create list
        lst = []
        cur = head
        while cur: 
            lst.append(cur.val)
            cur = cur.next
        
        l, r = 0, len(lst) - 1

        # l == r 인 경우는 이미 값이 같기때문에 상관없지만 그냥 넣음
        while l <= r:
            if lst[l] != lst[r]: 
                return False
            l += 1
            r -= 1
        return True
        
