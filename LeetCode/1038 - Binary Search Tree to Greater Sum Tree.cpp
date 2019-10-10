class Solution
{
public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int greater = 0;
        dfs(root, greater);
        return root;
    }

    void dfs(TreeNode *root, int &greater)
    {
        if (!root)
            return;

        dfs(root->right, greater);
        root->val += greater;
        greater = root->val;
        dfs(root->left, greater);
    }
};
