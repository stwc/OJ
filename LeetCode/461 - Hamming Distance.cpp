class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        bitset<32> bs(x ^ y);
        return bs.count();
    }
};
