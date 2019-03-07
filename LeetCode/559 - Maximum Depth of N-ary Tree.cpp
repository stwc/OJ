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
    int rst = 0;
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        if (root->children.size() == 0)
            return 1;
        int depth = 1;
        dfs(root, depth);
        return rst;
    }

    void dfs(Node *root, int depth)
    {
        for (auto it = root->children.begin(); it != root->children.end();
             ++it) {
            if (*it != NULL) {
                rst = max(rst, ++depth);
                break;
            }
        }
        for (auto it = root->children.begin(); it != root->children.end();
             ++it) {
            if (*it != NULL)
                dfs(*it, depth);
        }
    }
};