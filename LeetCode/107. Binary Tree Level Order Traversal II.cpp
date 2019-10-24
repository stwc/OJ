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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root)
            return vector<vector<int>>();
        stack<vector<int>> s;
        bfs(root, s);
        vector<vector<int>> ret;
        while (!s.empty()) {
            vector<int> tmp = s.top();
            s.pop();
            ret.push_back(tmp);
        }
        return ret;
    }

    void bfs(TreeNode *root, stack<vector<int>> &s)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            vector<int> tmp;
            while (cnt--) {
                TreeNode *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            s.push(tmp);
        }
    }
};
