#include <stdio.h>

int main()
{
    long int d;
    while (scanf("%ld", &d) > 0) {
        long int a = 0, b = 1;
        long int sum = 0;
        for (int i = 1; i <= 50; ++i) {
            b += a;
            sum += b;
            a = 1 + d * (i - 1);
        }

        printf("%ld\n", sum);
    }
    return 0;
}