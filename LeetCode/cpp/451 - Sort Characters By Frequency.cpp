class Solution {
public:
    string frequencySort(string s) {
        pair<int, char> dict[128];
        for (int i = 0; i < 128; ++i) {
            dict[i].first = 0;
            dict[i].second = i;
        }
        for (auto i: s)
            --dict[i].first;
        sort(dict, dict + 128);
        string temp;
        for (int i = 0; dict[i].first != 0; ++i) {
            dict[i].first = -dict[i].first;
            while (dict[i].first--)
                temp.push_back(dict[i].second);
        }
        return temp;
    }
};