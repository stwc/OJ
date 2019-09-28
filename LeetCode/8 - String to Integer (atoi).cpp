

class Solution
{
public:
    int myAtoi(string str)
    {
        bool sign = false;
        int num = 0, i;
        // Ignore spaces
        for (i = 0; i < str.size() && str[i] == ' '; ++i)
            ;

        if (str[i] == '-' || str[i] == '+') {
            if (str[i] == '-') {
                sign = true;
            }
            ++i;
        }

        // Ignore leading zeros
        for (; i < str.size() && str[i] == '0'; ++i)
            ;

        for (; str[i] >= '0' && str[i] <= '9'; ++i) {
            if (num > INT32_MAX / 10 ||
                num == INT32_MAX / 10 && (str[i] - '0') >= 8)
                return (sign) ? INT32_MIN : INT32_MAX;
            num = num * 10 + (str[i] - '0');
        }
        return (sign) ? -num : num;
    }
};
