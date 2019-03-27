class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        if (A.size() == A[0].size()) {
            for (int i = 0; i < A.size(); ++i)
                for (int j = i + 1; j < A.size(); ++j)
                    swap(A[i][j], A[j][i]);
            return A;
        } else {
            vector<vector<int>> res(A[0].size());
            for (int i = 0; i < res.size(); ++i)
                res[i].resize(A.size());

            for (int i = 0; i < A.size(); ++i)
                for (int j = 0; j < A[0].size(); ++j)
                    res[j][i] = A[i][j];
            return res;
        }
    }
};