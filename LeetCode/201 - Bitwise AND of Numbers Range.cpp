class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        if (m == 0)
            return 0;

        int mask = n - m;
        mask = ~mask;
        int ret = m & n;
        while (~mask) {
            ret &= mask;
            mask >>= 1;
        }
        return ret;
    }
};
