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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        dfs(root, res, 0);
        return res;
    }

    void dfs(TreeNode *root, vector<vector<int>> &res, int cur)
    {
        if (!root)
            return;

        if (res.size() < cur + 1)
            res.push_back({root->val});
        else
            res[cur].push_back(root->val);

        if (root->left)
            dfs(root->left, res, cur + 1);
        if (root->right)
            dfs(root->right, res, cur + 1);
    }
};