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
    int sum = 0;
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        dfs(root, L, R);
        return sum;
    }

    void dfs(TreeNode *root, int L, int R)
    {
        if (root->val <= R && root->val >= L)
            sum += root->val;
        if (root->left)
            dfs(root->left, L, R);
        if (root->right)
            dfs(root->right, L, R);
    }
};