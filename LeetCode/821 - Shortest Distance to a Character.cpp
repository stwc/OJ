class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> vec;
        int n = S.size();
        int idx = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (S[i] == C)
                idx = i;
            vec.push_back(abs(i - idx));
        }
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C)
                idx = i;
            vec[i] = min(vec[i], abs(i - idx));
        }
        return vec;
    }
};