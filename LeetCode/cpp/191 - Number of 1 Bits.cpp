class Solution1
{
public:
    int hammingWeight(uint32_t n)
    {
        bitset<32> bs(n);
        return bs.count();
    }
};

class Solution2
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        while (n > 0) {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }
};

class Solution3
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        while (n) {
            n &= n - 1;
            ++cnt;
        }
        return cnt;
    }
};
