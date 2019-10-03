// Runtime: 12 ms, faster than 9.13% of C++ online submissions
// Why so slow?
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        vector<int> ret;
        while (l <= r) {
            if (numbers[l] + numbers[r] == target) {
                ret.push_back(l + 1);
                ret.push_back(r + 1);
                return ret;
            } else if (numbers[l] + numbers[r] < target) {
                ++l;
            } else {
                --r;
            }
        }
        return vector<int>();
    }
};
