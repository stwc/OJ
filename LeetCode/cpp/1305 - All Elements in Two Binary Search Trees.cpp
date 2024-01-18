// Runtime: 276 ms, faster than 69.89%.
// Memory Usage: 60.5 MB, less than 100.00%.

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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return vector<int>();
        vector<int> ret, v1, v2;
        int cnt1 = 0, cnt2 = 0;
        dfs(root1, v1, cnt1);
        dfs(root2, v2, cnt2);
        int i = 0, j = 0;
        while (i < cnt1 && j < cnt2) {
            if (v1[i] < v2[j])
                ret.push_back(v1[i++]);
            else
                ret.push_back(v2[j++]);
        }
        while (i < cnt1)
            ret.push_back(v1[i++]);
        while (j < cnt2)
            ret.push_back(v2[j++]);
        return ret;
    }

    void dfs(TreeNode *root, vector<int> &v, int &cnt)
    {
        if (!root)
            return;
        if (root->left)
            dfs(root->left, v, cnt);
        v.push_back(root->val);
        ++cnt;
        if (root->right)
            dfs(root->right, v, cnt);
    }
};
