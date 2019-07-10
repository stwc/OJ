class Solution
{
public:
    vector<vector<int>> ret;

    vector<vector<int>> permute(vector<int> &nums)
    {
        perm(nums, 0, nums.size());
        return ret;
    }

    void perm(vector<int> &nums, int front, int end)
    {
        if (front == end) {
            ret.push_back(nums);
        } else {
            for (int i = front; i < end; ++i) {
                swap(nums[front], nums[i]);
                perm(nums, front + 1, end);
                swap(nums[front], nums[i]);
            }
        }
    }
};
