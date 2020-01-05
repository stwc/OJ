class Solution {
public:
    string freqAlphabets(string s) {
        int len = s.size();
        string ret;
        for (int i = 0; i < len; ++i) {
            if (i + 2 < len && s[i + 2] == '#') {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0') - 1;
                char c = 'a' + num;
                string tmp(1, c);
                ret += tmp;
                i += 2;
            } else {
                char c = s[i] -'1' + 'a';
                string tmp(1, c);
                ret += tmp;
            }
        }
        return ret;
    }
};
