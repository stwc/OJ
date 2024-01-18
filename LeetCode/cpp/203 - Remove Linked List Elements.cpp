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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return head;

        ListNode *prev = new ListNode(0);
        prev->next = head;
        ListNode *cur = head;
        ListNode *tmp = prev;
        while (cur) {
            if (cur->val == val && cur->next) {
                prev->next = cur->next;
                cur = prev->next;
            } else if (cur->val == val && !cur->next) {
                prev->next = NULL;
                break;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        head = tmp->next;
        return head;
    }
};
