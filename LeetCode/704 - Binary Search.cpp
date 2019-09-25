// Runtime: 56 ms, faster than 16.46% of C++ online submissions
// Why so slow?
class Solution1
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (target > nums[mid])
                l = mid + 1;
            else
                r = mid;
        }
        if (nums[l] == target)
            return l;
        return -1;
    }
};

class Solution2
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (target > nums[mid])
                l = mid + 1;
            else if (target < nums[mid])
                r = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};
