# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution1:
    """space: O(n)"""

    def hasCycle(self, head: Optional[ListNode]) -> bool:
        visited = set[ListNode]()

        while not head:
            if head in visited:
                return True

            visited.add(head)
            head = head.next

        return False


class Solution2:
    """space: O(1)"""

    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow_ptr = head
        fast_ptr = head

        while slow_ptr and fast_ptr and fast_ptr.next:
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next

            if slow_ptr == fast_ptr:
                return True

        return False
