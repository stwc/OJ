class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> cnt;
        for (int i = 0; i < arr.size(); ++i) {
            if (cnt.count(arr[i]) > 0)
                ++cnt[arr[i]];
            else
                cnt.insert({arr[i], 1});
        }

        unordered_set<int> dup;
        for (auto it : cnt) {
            if (dup.count(it.second) > 0)
                return false;
            else
                dup.insert(it.second);
        }
        return true;
    }
};
