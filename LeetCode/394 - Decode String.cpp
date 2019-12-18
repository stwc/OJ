// Method1: using two stacks
// Method2: recursion

#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define LOCAL 0

class Solution
{
public:
    string decodeString(string s)
    {
        string ret;
        stack<int> s_cnt;
        stack<string> s_str;
        int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            // cout << "# loop " << i << endl;  // DEBUG
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                // DEBUG
                // cout << "  Counter:" << num << endl;
                // cout << "  String: " << ret << endl;
                s_cnt.push(num);
                s_str.push(ret);
                num = 0;
                ret.clear();
            } else if (s[i] == ']') {
                int num = s_cnt.top();
                s_cnt.pop();
                string tmp;
                if (!s_str.empty()) {
                    tmp = s_str.top();
                    s_str.pop();
                    while (num--)
                        tmp += ret;
                    ret = tmp;
                } else {
                    tmp = ret;
                    while (--num)
                        ret += tmp;
                }
                // cout << "  ]Stack: " << ret << endl;  // DEBUG
            } else {
                ret += s[i];
            }
        }
        return ret;
    }
};

#if LOCAL == 1
void test()
{
    // Testcase:
    // s = "3[a]2[bc]", return "aaabcbc".
    // s = "3[a2[c]]", return "accaccacc".
    // s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

    Solution s;
    string t1 = s.decodeString("3[a]2[bc]");
    string a1 = "aaabcbc";
    if (!(t1 == a1)) {
        cout << "--- Testcase 1 failed ---" << endl;
        cout << "  Output:   " << t1 << endl;
        cout << "  Expected: " << a1 << endl;
        exit(1);
    } else {
        cout << "--- Testcase 1 passed ---" << endl;
    }

    string t2 = s.decodeString("3[a2[c]]");
    string a2 = "accaccacc";
    if (!(t2 == a2)) {
        cout << "--- Testcase 2 failed ---" << endl;
        cout << "  Output:   " << t2 << endl;
        cout << "  Expected: " << a2 << endl;
        exit(1);
    } else {
        cout << "--- Testcase 2 passed ---" << endl;
    }

    string t3 = s.decodeString("2[abc]3[cd]ef");
    string a3 = "abcabccdcdcdef";
    if (!(t3 == a3)) {
        cout << "--- Testcase 3 failed ---" << endl;
        cout << "  Output:   " << t3 << endl;
        cout << "  Expected: " << a3 << endl;
        exit(1);
    } else {
        cout << "--- Testcase 3 passed ---" << endl;
    }
}


int main()
{
    test();
    return 0;
}
#endif
