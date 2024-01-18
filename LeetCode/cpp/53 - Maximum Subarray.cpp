class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> pre_sum, pre_min;
        int neg_max = INT_MIN;
        pre_sum.push_back(0);
        pre_min.push_back(0);
        for (int i = 1; i <= nums.size(); ++i) {
            pre_sum.push_back(pre_sum[i - 1] + nums[i - 1]);
            neg_max = max(neg_max, nums[i - 1]);
        }
          
        int ans = INT_MIN;
        for (int i = 1; i <= nums.size(); ++i) {
            pre_min.push_back(min(pre_min[i - 1], pre_sum[i]));
            ans = max(ans, pre_sum[i] - pre_min[i - 1]);
        }
        if (ans == 0 && neg_max < 0)
            return neg_max;
        else
            return ans;
    }
};