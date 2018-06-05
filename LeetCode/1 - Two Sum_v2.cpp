class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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
