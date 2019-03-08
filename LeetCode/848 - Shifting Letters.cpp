class Solution
{
public:
    string shiftingLetters(string S, vector<int> &shifts)
    {
        int len = S.size();
        for (int i = len - 2; i >= 0; --i)
            shifts[i] = (shifts[i] % 26) + shifts[i + 1];
        for (int i = 0; i < len; ++i)
            S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
        return S;
    }
};