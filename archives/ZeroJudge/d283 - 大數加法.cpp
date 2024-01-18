// Unfinished

#include <bits/stdc++.h>
using namespace std;

#define N 100
#define W 256

int main()
{
    //int nu;
    //cin >> nu;
    int f[3][N];
    memset(f, 0, sizeof(f));

    f[0][0] = 0;
    f[1][0] = 1;
        
    int carry = 0;
    for (int i = 2; i < 3; ++i) {
        for (int j = 0; j < W; ++j) {
            f[2][j] = f[1][j] + f[0][j] + carry;
            if (f[2][j] >= 10) {
                carry++;
                f[2][j] %= 10;
            }
            else
                carry = 0;
        }
        for (int k = 0; k < W; ++k) {
            f[0][k] = f[1][k];
            f[1][k] = f[2][k];
        }
    }

    int len;
    for (len = W - 1;; --len)
        if (f[2][len] > 0) break;

    for (int i = len; i >= 0; --i)
        cout << f[2][i];
    cout << '\n';
    return 0;
}