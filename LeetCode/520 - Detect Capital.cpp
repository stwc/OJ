class Solution {
public:
    bool detectCapitalUse(string word) {
        char *str = new char[word.length() + 1];
        strcpy(str, word.c_str());
        if (islower(str[0])) {
            for (int i = 1; i < strlen(str); ++i)
                if (isupper(str[i]))
                    return false;
        } else {
            if (isupper(str[1])) {
                for (int i = 2; i < strlen(str); ++i)
                    if (islower(str[i]))
                        return false;
            } else {
                for (int i = 2; i < strlen(str); ++i)
                    if (isupper(str[i]))
                        return false;
            }
        }
        return true;
    }
};
