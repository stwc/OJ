# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution1:
    """
    space: O(n)
    """

    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        nums = []
        mid = 0

        while head:
            nums.append(head)
            mid += 1
            head = head.next

        return nums[mid // 2]


class Solution2:
    """
    space: O(1)
    """

    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        return slow
