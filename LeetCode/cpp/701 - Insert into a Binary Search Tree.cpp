/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newNode = new TreeNode(val);
        if (!root)
            return newNode;
        dfs(root, newNode);
        return root;
    }
    void dfs(TreeNode *root, TreeNode *newNode)
    {
        if (newNode->val < root->val) {
            if (root->left) {
                dfs(root->left, newNode);
            } else {
                root->left = newNode;
                return;
            }
        }
        if (newNode->val > root->val) {
            if (root->right) {
                dfs(root->right, newNode);
            } else {
                root->right = newNode;
                return;
            }
        }
    }
};