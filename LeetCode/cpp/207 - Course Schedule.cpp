// Detect Cycle in Directed Graph
// Time: O(V+E)

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> g(numCourses, vector<int>());
        int indegree[numCourses + 1] = {};
        for (int i = 0; i < prerequisites.size(); ++i) {
            int u = prerequisites[i].back();
            int v = prerequisites[i].front();
            g[u].push_back(v);
            ++indegree[v];
        }

        queue<int> Q;
        int n = numCourses;
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                Q.push(i);

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto v : g[u])
                if (--indegree[v] == 0)
                    Q.push(v);
            --n;
        }
        return n == 0;
    }
};
