/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *recoverFromPreorder(string S)
    {
        vector<TreeNode *> stack;
        for (int i = 0; i < S.size();) {
            int val = 0, lv = 1;
            for (; S[i] == '-'; ++i)
                ++lv;
            while (i < S.size() && S[i] != '-')
                val = val * 10 + (S[i++] - '0');
            TreeNode *node = new TreeNode(val);

            while (lv <= stack.size())
                stack.pop_back();
            if (!stack.empty()) {
                if (!stack.back()->left)
                    stack.back()->left = node;
                else
                    stack.back()->right = node;
            }
            stack.push_back(node);
        }
        return stack[0];
    }
};
