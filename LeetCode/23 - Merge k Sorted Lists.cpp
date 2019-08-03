// Method: Brute Force, Time complexity: O(NlogN)
// It can be optimized by using priority queue

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
    static bool cmp(ListNode *l, ListNode *r)
    {
        if (!l)
            return false;
        if (!r)
            return false;
        return l->val < r->val;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        sort(lists.begin(), lists.end(), cmp);
        ListNode *ret = NULL;
        for (size_t i = 0; i < lists.size(); ++i) {
            ret = merge(ret, lists[i]);
        }
        return ret;
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};
