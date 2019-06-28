class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int ret = 0;
        bool visited[20000] = {false};
        for (int i = 0; i < nums.size(); ++i) {
            int len = 0, pos = i;
            while (1) {
                if (visited[pos])
                    break;
                visited[pos] = true;
                ++len;
                pos = nums[pos];
            }
            ret = max(ret, len);
        }
        return ret;
    }
};
