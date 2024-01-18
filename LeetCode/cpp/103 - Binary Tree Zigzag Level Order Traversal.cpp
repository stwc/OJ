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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return vector<vector<int>>();
        vector<vector<int>> ret;
        queue<TreeNode *> q;
        q.push(root);
        int cnt = 0, lv = 0;
        while (!q.empty()) {
            cnt = q.size();
            vector<int> tmp;
            while (cnt--) {
                TreeNode *r = q.front();
                q.pop();
                tmp.push_back(r->val);
                if (r->left)
                    q.push(r->left);
                if (r->right)
                    q.push(r->right);
            }
            if (lv++ % 2 == 1) {
                for (int i = 0, j = tmp.size() - 1; i < j; ++i, --j)
                    swap(tmp[i], tmp[j]);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
