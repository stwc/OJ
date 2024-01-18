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
    int sol;

    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        sol = 999999;
        dfs(root, 1);
        return sol;
    }

    void dfs(TreeNode *root, int cur)
    {
        if (!root->left && !root->right) {
            sol = min(sol, cur);
            return;
        }
        if (root->left)
            dfs(root->left, cur + 1);
        if (root->right)
            dfs(root->right, cur + 1);
    }
};
