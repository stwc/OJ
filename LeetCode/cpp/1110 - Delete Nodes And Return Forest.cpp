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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> forest;
        unordered_set<int> delVal;
        for (int i : to_delete)
            delVal.insert(i);
        dfs(root, nullptr, delVal, forest);
        return forest;
    }

    void dfs(TreeNode *root,
             TreeNode *parent,
             unordered_set<int> &delVal,
             vector<TreeNode *> &forest)
    {
        if (!root)
            return;

        if (delVal.count(root->val) != 0) {
            if (parent && parent->left == root)
                parent->left = nullptr;
            else if (parent)
                parent->right = nullptr;
            parent = nullptr;
        } else {
            if (!parent)
                forest.push_back(root);
            parent = root;
        }

        dfs(root->left, parent, delVal, forest);
        dfs(root->right, parent, delVal, forest);
    }
};
