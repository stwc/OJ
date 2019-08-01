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
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;

        stack<int> s;
        dfs(root, s);
        int pre = s.top();
        s.pop();
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            if (cur >= pre)
                return false;
            pre = cur;
        }
        return true;
    }

    void dfs(TreeNode *root, stack<int> &s)
    {
        if (!root)
            return;
        dfs(root->left, s);
        s.push(root->val);
        dfs(root->right, s);
    }
};
