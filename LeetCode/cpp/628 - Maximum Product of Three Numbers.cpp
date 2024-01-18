class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int rst = max(nums[len - 3] * nums[len - 2] * nums[len - 1],
                      nums[0] * nums[1] * nums[len - 1]);
        return rst;
    }
};