// Runtime: 228 ms, faster than 28.49%
// Memory Usage: 38.2 MB, less than 100.00%
// Need to be optimized

class Solution
{
public:
    const int MAX = 1e5 + 1;

    int jobScheduling(vector<int> &startTime,
                      vector<int> &endTime,
                      vector<int> &profit)
    {
        int len = profit.size(), dp[len + 1];
        vector<vector<int>> jobs;
        jobs.push_back({});
        for (int i = 0; i < len; ++i)
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());

        map<int, int, greater<int>> m;
        m.insert({0, dp[0] = 0});
        for (int i = 1; i <= len; ++i) {
            auto it = m.lower_bound(jobs[i][1]);
            dp[i] = max(dp[i - 1], jobs[i][2] + it->second);
            it = m.insert(m.begin(), {jobs[i][0], dp[i]});
            it->second = max(it->second, dp[i]);
        }
        return dp[len];
    }
};
