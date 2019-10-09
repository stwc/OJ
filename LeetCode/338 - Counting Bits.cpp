// Runtime: 56 ms, faster than 51.96%
class Solution1
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1);
        dp[0] = 0;
        int last = 0;
        for (int i = 1; i <= num; ++i) {
            if ((i & (i - 1)) == 0) {
                dp[i] = 1;
                last = i;
            } else {
                dp[i] = 1 + dp[i - last];
            }
        }
        return dp;
    }
};

// Runtime: 56 ms, faster than 51.96%
class Solution2
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1);
        dp[0] = 0;
        if (num == 0)
            return dp;
        dp[1] = 1;
        if (num == 1)
            return dp;
        int last2 = 1;
        for (int i = 2; i <= num; ++i) {
            if (i == (last2 << 1)) {
                dp[i] = 1;
                last2 <<= 1;
            } else {
                dp[i] = 1 + dp[i - last2];
            }
        }
        return dp;
    }
};

// Runtime: 48 ms, faster than 99.87%
class Solution3
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1);
        dp[0] = 0;
        if (num == 0)
            return dp;
        dp[1] = 1;
        if (num == 1)
            return dp;
        dp[2] = 1;
        if (num == 2)
            return dp;
        int last2 = 2, next2 = 4;
        for (int i = 3; i <= num; ++i) {
            if (i & next2) {
                dp[i] = 1;
                last2 = next2;
                next2 <<= 1;
            } else {
                dp[i] = 1 + dp[i - last2];
            }
        }
        return dp;
    }
};
