class Solution
{
public:
    int fib(int N)
    {
        if (N < 2)
            return N;
        int f0 = 0, f1 = 1, ret = 0;
        for (int i = 0; i < N - 1; ++i) {
            int tmp = ret;
            ret = f1 + f0;
            f0 = f1;
            f1 = ret;
        }
        return ret;
    }
};
