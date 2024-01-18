class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int count_zeros = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 0)
                ++count_zeros;
        }

        int len = arr.size() + count_zeros;
        for (int i = arr.size() - 1, j = len - 1; i >= 0; --i, --j) {
            if (j < arr.size())
                arr[j] = arr[i];
            if (arr[i] == 0 && --j < arr.size())
                arr[j] = 0;
        }
    }
};
