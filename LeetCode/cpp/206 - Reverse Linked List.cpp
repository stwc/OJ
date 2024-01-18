/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = NULL, *previous = NULL;
        while (head) {
            temp = head->next;
            head->next = previous;
            previous = head;
            head = temp;
        }
        return head = previous;
    }
};