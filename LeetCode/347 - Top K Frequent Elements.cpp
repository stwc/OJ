// Complexity: O(nlogn)
// Runtime: 28 ms, faster than 18.70%
// Memory Usage: 11.5 MB, less than 67.74%
typedef pair<int, int> pii;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> m;        // (num, cnt)
        priority_queue<pii> q;  // (cnt, num)
        for (int num : nums) {
            auto ret = m.insert({num, 1});
            if (!ret.second)
                ++m[num];
        }
        for (auto i : m)
            q.push({i.second, i.first});
        vector<int> ans;
        while (k--) {
            pii top = q.top();
            q.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};
