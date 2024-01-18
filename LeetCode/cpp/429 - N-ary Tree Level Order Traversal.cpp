/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    int maxdepth = 0;
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res(1000);
        dfs(root, res, 0);
        res.resize(maxdepth);
        return res;
    }

    void dfs(Node *root, vector<vector<int>> &res, int cur)
    {
        if (!root)
            return;
        res[cur++].push_back(root->val);
        maxdepth = max(maxdepth, cur);
        for (auto &it : root->children)
            dfs(it, res, cur);
    }
};