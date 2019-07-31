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
    int ret = 0;
    
    int countNodes(TreeNode *root) 
    {
        if (!root)
            return 0;
        ++ret;
        countNodes(root->left);
        countNodes(root->right);
        return ret;
    }
};
