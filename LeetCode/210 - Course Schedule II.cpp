// Detect Cycle in Directed Graph
// Time: O(V+E)

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
#endif

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> g(numCourses, vector<int>());
        int indegree[numCourses + 1] = {};
        for (int i = 0; i < prerequisites.size(); ++i) {
            int u = prerequisites[i].back();
            int v = prerequisites[i].front();
            g[u].push_back(v);
            ++indegree[v];
        }

        int n = numCourses;
        queue<int> Q;
        vector<int> ret;
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                Q.push(i);

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            --n;
            ret.push_back(u);
            for (auto v : g[u])
                if (--indegree[v] == 0)
                    Q.push(v);
        }

        if (n != 0)
            return vector<int>();
        return ret;
    }
};
