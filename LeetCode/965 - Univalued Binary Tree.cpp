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
    bool flag = true;
    bool isUnivalTree(TreeNode *root)
    {
        if (root->left) {
            if (root->val != root->left->val)
                return flag = false;
            isUnivalTree(root->left);
        }
        if (root->right) {
            if (root->val != root->right->val)
                return flag = false;
            isUnivalTree(root->right);
        }
        return flag;
    }
};