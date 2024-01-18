#include <stdio.h>
#include <math.h>

#define MAX 100000000

void table(long long int prime[])
{
    long long int i, j, k;
    for (i = 0; i < MAX; ++i)
        prime[i] = 1;

    prime[0] = 0;
    prime[1] = 0;

    for (i = 2; i <= sqrt(MAX); ++i) {
        if (prime[i]) {
            for (k = (MAX - 1) / i, j = i * k; k >= i; --k, j -= i) {
                if (prime[k])
                    prime[j] = 0;
            }
        }
    }
}

int main()
{
    long long int prime[MAX];
    table(prime);
    long long int a, b;

    while (scanf("%lld %lld", &a, &b) > 0) {
        int count = 0;
        for (; a >= b; ++a) {
            if (prime[a] == 1)
                count++;
        }
        printf("%d\n", count);
    }
}