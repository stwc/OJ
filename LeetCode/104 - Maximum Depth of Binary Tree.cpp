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
    int rst = 0;
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int depth = 1;
        dfs(root, depth);
        return rst;
    }

    void dfs(TreeNode *root, int depth)
    {
        if (root->left || root->right) {
            depth++;
            rst = max(rst, depth);
        }
        if (root->left)
            dfs(root->left, depth);
        if (root->right)
            dfs(root->right, depth);
    }
};