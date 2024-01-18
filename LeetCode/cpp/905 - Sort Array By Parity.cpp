// Need to be improved
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> odd, even;
        for (int it: A) {
            if (it % 2 == 1)
                odd.push_back(it);
            else
                even.push_back(it);
        }
        for (int it: odd)
            even.push_back(it);
        return A = even;
    }
};