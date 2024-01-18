#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    while (1) {
        getline(cin, line);
        if (line[0] == '0') break;

        int rst = 0;
        for (int i = 0; i < line.size(); ++i) {
            rst = (rst * 10 + line[i] - '0') % 17;
        }

        if (rst == 0) printf("1\n");
        else printf("0\n");
    }
    return 0;
}