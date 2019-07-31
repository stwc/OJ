class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 0)
            return 1;
        if (num == 1)
            return 0;

        int sum = 0, rem = 0, pos = 1;
        while (num != 1) {
            rem = (num % 2) ^ 1;
            sum = sum + rem * pos;
            num /= 2;
            pos *= 2;
        }
        return sum;
    }
};
