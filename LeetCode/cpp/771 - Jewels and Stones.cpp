class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        if (J.size() == 0 || S.size() == 0)
            return 0;
        set<int> mySet;
        for (int i = 0; i < J.size(); ++i)
            mySet.insert(J[i]);
        int cnt = 0;
        for (int i = 0; i < S.size(); ++i)
            if (mySet.count(S[i]))
                cnt++;
        return cnt;
    }
};