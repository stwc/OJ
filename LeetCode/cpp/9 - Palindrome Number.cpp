class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        int len = 0, tmp = x;
        while (tmp > 0) {
            ++len;
            tmp /= 10;
        }

        int hi = 0, lo = 0;
        int mid = len / 2, div = 1;
        for (int i = 0; i < mid; ++i)
            div *= 10;
        if (len % 2) {  // odd
            tmp = x / (div * 10);
            lo = x % div;
            for (int i = 0; i < mid; ++i) {
                hi = hi * 10 + (tmp % 10);
                tmp /= 10;
            }
        } else {  // even
            tmp = x / div;
            lo = x % div;
            for (int i = 0; i < mid; ++i) {
                hi = hi * 10 + (tmp % 10);
                tmp /= 10;
            }
        }
        // cout << "num: " << x << endl;
        // cout << "hi: " << hi << endl;
        // cout << "lo: " << lo << endl;
        return hi == lo;
    }
};
