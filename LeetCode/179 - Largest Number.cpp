class Solution
{
public:
    static bool cmp(string a, string b)
    {
        string opt1 = a + b;
        string opt2 = b + a;
        return opt1 > opt2;
    }

    string largestNumber(vector<int> &nums)
    {
        vector<string> s;
        for (auto it : nums)
            s.push_back(to_string(it));
        sort(s.begin(), s.end(), cmp);
        if (s[0] == "0")
            return "0";
        string sol;
        for (auto it : s)
            sol += it;
        return sol;
    }
};
