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
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (!t1) {
            if (!t2)
                return NULL;
            else
                return t2;
        } else {
            if (!t2)
                return t1;
            t1->val += t2->val;
        }

        dfs(t1, t2);
        return t1;
    }
    
    void dfs(TreeNode *t1, TreeNode* t2)
    {
        if (t1->left && t2->left) {
            t1->left->val += t2->left->val;
            dfs(t1->left, t2->left);
        } else if (!t1->left && t2->left) {
            t1->left = t2->left;
        }
        
        
        if (t1->right && t2->right) {
            t1->right->val += t2->right->val;
            dfs(t1->right, t2->right);
        } else if (!t1->right && t2->right) {
            t1->right = t2->right;
        }
        
    }
};
