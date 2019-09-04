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
    int maxLevelSum(TreeNode *root)
    {
        int maxLevel = 1, maxVal = root->val, depth = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size(), sum = 0;
            while (n--) {
                TreeNode *r = q.front();
                q.pop();
                sum += r->val;
                if (r->left)
                    q.push(r->left);
                if (r->right)
                    q.push(r->right);
            }
            if (sum > maxVal) {
                maxVal = sum;
                maxLevel = depth;
            }
            ++depth;
        }

        return maxLevel;
    }
};
