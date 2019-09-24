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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *digit = new ListNode(0), *ret = digit;
        bool carry = false;
        while (l1 && l2) {
            int sum = l1->val + l2->val + ((carry) ? 1 : 0);
            if (sum > 9) {
                carry = true;
                digit->val = sum % 10;
            } else {
                carry = false;
                digit->val = sum;
            }
            l1 = l1->next;
            l2 = l2->next;
            if (l1 && l2) {
                digit->next = new ListNode(0);
                digit = digit->next;
            }
        }

        if (l1)
            digit->next = l1;
        if (l2)
            digit->next = l2;

        while (carry) {
            if (digit->next) {
                digit->next->val += 1;
                if (digit->next->val > 9) {
                    carry = true;
                    digit->next->val %= 10;
                } else {
                    carry = false;
                }
            } else {
                digit->next = new ListNode(1);
                break;
            }
            digit = digit->next;
        }
        return ret;
    }
};
