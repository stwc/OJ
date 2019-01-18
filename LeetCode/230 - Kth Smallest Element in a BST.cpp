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
    int ans, count;
    int kthSmallest(TreeNode *root, int k)
    {
        count = 0;
        dfs(root, k);
        return ans;
    }
    
    void dfs(TreeNode *root, int k)
    {
        if (root->left)
            dfs(root->left, k);
        
        if (++count == k)
            ans = root->val;
        
        if (root->right)
            dfs(root->right, k);
    }
};