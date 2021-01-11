# https://leetcode.com/problems/reorder-list/

# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution:

    def printList(self, head):
        cur = head
        plis = ""
        while cur:
            plis += str(cur.val) + " "
            cur = cur.next
        print(plis)

    def reverseList(self, head):
        # 1 2 3 4 5
        if head == None:
            return None

        prev = None
        cur = head
        while cur.next:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
        cur.next = prev

        return cur

    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        # edge case
        if head == None:
            return None
        if head.next == None:
            return head

        # find midpoint
        slow = head
        fast = head.next
        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        print(slow.val)
        print(fast.val)

        # new heads
        # 1 2 3 4
        # 1 2 3
        head1 = head
        head2 = slow.next
        slow.next = None
        head2 = self.reverseList(head2)

        self.printList(head1)
        self.printList(head2)

        temp = ListNode()
        while head1 or head2:
            if head1:
                temp.next = head1
                temp = temp.next
                head1 = head1.next

            if head2:
                temp.next = head2
                temp = temp.next
                head2 = head2.next

        self.printList(head)

head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, None)))))
test = Solution()
test.reorderList(head)