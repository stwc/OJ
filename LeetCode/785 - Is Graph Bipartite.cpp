// Runtime: 28 ms, faster than 37.66%
// Using DFS, need to be optimized

class Solution
{
public:
    int depth[101] = {-1};
    bool visited[101] = {false};

    bool isBipartite(vector<vector<int>> &graph)
    {
        if (graph.size() == 0)
            return false;

        for (int i = 0; i < graph.size(); ++i)
            if (!visited[i])
                dfs(graph, 0, i);
        for (int i = 0; i < graph.size(); ++i)
            for (int j = 0; j < graph[i].size(); ++j)
                if (depth[i] % 2 == depth[graph[i][j]] % 2)
                    return false;
        return true;
    }

    void dfs(vector<vector<int>> &graph, int lv, int s)
    {
        visited[s] = true;
        depth[s] = lv;
        for (int i = 0; i < graph[s].size(); ++i)
            if (!visited[graph[s][i]])
                dfs(graph, lv + 1, graph[s][i]);
    }
};
