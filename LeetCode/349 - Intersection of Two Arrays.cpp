class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ret;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums1.size(); ++i) {
            if (!freq.count(nums1[i]))
                freq.insert({nums1[i], 1});
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (freq.count(nums2[i]) > 0)
                if (++freq[nums2[i]] == 2)
                    ret.push_back(nums2[i]);
        }
        return ret;
    }
};
