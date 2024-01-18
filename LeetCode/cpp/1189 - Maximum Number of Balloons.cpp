class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int cnt[26] = {};
        for (int i = 0; i < text.size(); ++i)
            ++cnt[text[i] - 'a'];
        int b = cnt['b' - 'a'];
        int a = cnt['a' - 'a'];
        int l = cnt['l' - 'a'] / 2;
        int o = cnt['o' - 'a'] / 2;
        int n = cnt['n' - 'a'];

        int ret = min(b, min(a, n));
        if (ret == 0 || l == 0 || o == 0)
            return 0;
        else
            return min(ret, min(l, o));
    }
};
