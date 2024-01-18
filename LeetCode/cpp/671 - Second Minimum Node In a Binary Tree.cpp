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
    int min1, min2;
    
    int findSecondMinimumValue(TreeNode *root)
    {
        if (!root->left && !root->right || root->left->val == root->right->val)
            return -1;
        
        if (root->left->val < root->right->val) {
            min1 = root->left->val;
            min2 = root->right->val;
            dfs(root->left);
        } else {
            min1 = root->right->val;
            min2 = root->left->val;
            dfs(root->right);
        }
        return min2;
    }
    
    void dfs(TreeNode *root)
    {
        if (root->left) {
            int temp = max(root->left->val, root->right->val);
            if (root->left->val != root->right->val && temp < min2) {
                min1 = root->val;
                min2 = temp;
            }
            dfs(root->left);
        }
        if (root->right) {
            int temp = max(root->left->val, root->right->val);
            if (root->left->val != root->right->val && temp < min2) {
                min1 = root->val;
                min2 = temp;
            }
            dfs(root->right);
        }
    }
};