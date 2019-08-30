// Method1: diameter = max{every node's (lh + rh) while the path pass the node}
// Method2: run BFS twice

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
    int diameter = 0;

    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        // the path pass the node
        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        height(root);
        return diameter;
    }
};
