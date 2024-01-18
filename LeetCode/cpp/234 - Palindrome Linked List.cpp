/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;

        ListNode *first = head;
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }

        head = first;
        if (len % 2 == 0) {
            len /= 2;
        } else {
            len = len / 2 + 1;
        }
        while (len--)
            head = head->next;

        ListNode *second = reverseList(head);
        while (first && second) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL, *next = NULL;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
