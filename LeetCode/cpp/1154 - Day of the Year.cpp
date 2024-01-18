class Solution
{
public:
    int dayOfYear(string date)
    {
        const int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));

        bool is_leap_year = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;

        int ret = d + ((is_leap_year && m > 2) ? 1 : 0);
        for (int i = 0; i < m - 1; ++i)
            ret += month[i];
        return ret;
    }
};
