class Solution1
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        for (int i = 0; i < nums.size();) {
            if (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                ++i;
        }
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1)
                ret.push_back(nums[i]);
        }
        return ret;
    }
};

class Solution2
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            nums[abs(nums[i]) - 1] *= -1;
            if (nums[abs(nums[i]) - 1] > 0)
                ret.push_back(abs(nums[i]));
        }
        return ret;
    }
};
