class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ret;
        int i, freq[2001] = {};
        for (i = 0; i < arr1.size(); ++i)
            ++freq[arr1[i]];
        for (i = 0; i < arr2.size(); ++i)
            ++freq[arr2[i]];
        for (i = 0; i < arr3.size(); ++i)
            ++freq[arr3[i]];

        for (i = 1; i <= 2000; ++i)
            if (freq[i] == 3)
                ret.push_back(i);
        return ret;
    }
};