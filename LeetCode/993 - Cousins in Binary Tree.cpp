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
    bool isCousins(TreeNode *root, int x, int y)
    {
        pair<int, TreeNode *> nodeX(0, NULL), nodeY(0, NULL);
        dfs(nodeX, root, x, 0);
        dfs(nodeY, root, y, 0);
        // cout << "depthX=" << nodeX.first << ", depthY=" << nodeY.first <<
        // endl;
        if (nodeX.first == nodeY.first && nodeX.second != nodeY.second)
            return true;
        return false;
    }

    void dfs(pair<int, TreeNode *> &node, TreeNode *root, int x, int cur)
    {
        if (root->left) {
            if (root->left->val == x) {
                node.first = cur + 1;
                node.second = root;
                return;
            }
            dfs(node, root->left, x, cur + 1);
        }
        if (root->right) {
            if (root->right->val == x) {
                node.first = cur + 1;
                node.second = root;
                return;
            }
            dfs(node, root->right, x, cur + 1);
        }
    }
};