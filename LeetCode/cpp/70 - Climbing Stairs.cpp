class Solution
{
public:
    int climbStairs(int n)
    {
        int f0 = 1, f1 = 1, tmp;
        for (int i = 2; i <= n; ++i) {
            tmp = f0;
            f0 += f1;
            f1 = tmp;
        }
        return f0;
    }
};
