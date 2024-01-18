#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

vector<int> e[MAX_N];

pair<long long, long long> dfs(int a, int parent)
{
    long long black = 1, white = 1;
    for (int b : e[a]) {
        if (b != parent) {
            pair<long long, long long> p = dfs(b, a);
            black = (black * p.second) % MOD;
            white = (white * ((p.first + p.second) % MOD)) % MOD;
        }
    }
    return {black, white};
}

int main()
{
    int n;
    scanf("%d", &n);
    while (--n) {
        int a, b;
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }

    pair<long long, long long> ret = dfs(1, -1);
    printf("%lld\n", (ret.first + ret.second) % MOD);
    return 0;
}
