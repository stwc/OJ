class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int len = S.size();
        for (int i = 0, j = len - 1; i < j;) {
            if (isalpha(S[i]) && isalpha(S[j])) {
                char tmp = S[i];
                S[i++] = S[j];
                S[j--] = tmp;
            }
            if (!isalpha(S[i]))
                ++i;
            if (!isalpha(S[j]))
                --j;
        }
        return S;
    }
};