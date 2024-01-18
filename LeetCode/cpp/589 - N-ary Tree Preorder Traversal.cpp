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
    vector<int> preorder(Node *root)
    {
        vector<int> res;
        dfs(res, root);
        return res;
    }

    void dfs(vector<int> &res, Node *root)
    {
        if (!root)
            return;

        res.push_back(root->val);
        for (auto &it : root->children)
            dfs(res, it);
    }
};