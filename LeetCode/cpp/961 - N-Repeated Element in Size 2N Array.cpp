class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        set<int> myset;
        for (int i = 0; i < A.size(); ++i) {
            if (!myset.count(A[i]))
                myset.insert(A[i]);
            else
                return A[i];
        }
        return -1;
    }
};
