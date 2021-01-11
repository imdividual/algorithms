# https://leetcode.com/problems/sort-list/

# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution:
    def printList(self, head):
        cur = head
        s = ""
        while cur:
            s += str(cur.val) + " "
            cur = cur.next
        print(s)

    def sortList(self, head: ListNode) -> ListNode:
        # edge case
        if head == None:
            return None
        if head.next == None:
            return head

        # split llist and recurse
        slow = head
        fast = head.next.next
        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        head1 = head
        head2 = slow.next
        slow.next = None
        head1 = self.sortList(head1)
        head2 = self.sortList(head2)
        self.printList(head1)
        self.printList(head2)

        # merge lists
        head = ListNode()
        temp = head
        while head1 or head2:
            if head2 == None or (head1 != None and head2 != None and head1.val < head2.val):
                temp.next = head1
                temp = temp.next
                head1 = head1.next
            else:
                temp.next = head2
                temp = temp.next
                head2 = head2.next
        return head.next

test = Solution()
head = ListNode(1, ListNode(3, ListNode(4, ListNode(2, ListNode(5, None)))))
test.printList(test.sortList(head))