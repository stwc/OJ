// Ituitive but inefficient
class Solution1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> sol;
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    sol.push_back(i);
                    sol.push_back(j);
                    return sol;
                }
            }
        }
    }
};

// Better
class Solution2
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i])) {
                ret.push_back(m[target - nums[i]]);
                ret.push_back(i);
                return ret;
            }
            m[nums[i]] = i;
        }
    }
};
