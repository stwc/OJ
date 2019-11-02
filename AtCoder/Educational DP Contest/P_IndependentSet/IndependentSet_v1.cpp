#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 5;

vector<int> e[MAX_N];
long long dp[MAX_N][2];

void dfs(int a, int parent = -1)
{
    if (dp[a][0] > 0 && dp[a][1] > 0)
        return;

    int dp0 = 1, dp1 = 1;
    for (int b : e[a]) {
        if (b != parent) {
            dfs(b, a);
            dp1 = (dp1 * dp[b][0]) % MOD;
            dp0 = (dp0 * ((dp[b][0] + dp[b][1]) % MOD)) % MOD;
        }
    }
    dp[a][0] = dp0;
    dp[a][1] = dp1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }

    for (int i = 0; i < n - 1; ++i)
        dp[i][0] = dp[i][1] = -1;

    dfs(1);
    printf("%lld\n", (dp[1][0] + dp[1][1]) % MOD);
    return 0;
}
