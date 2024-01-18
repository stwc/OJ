#include <stdio.h>
int main()
{
    long long int a, b, c;
    while (scanf("%lld %lld %lld", &a, &b, &c) > 0) {
        if (a > b && a > c) {
            if (b + c < a) {
                printf("A\n");
            }
            else {
                if (b > c) printf("B\n");
                else printf("C\n");
            }
        }
        else if (b > a && b > c) {
            if (a + c < b) {
                printf("B\n");
            }
            else {
                if (a > c) printf("A\n");
                else printf("C\n");
            }
        }
        else if (c > a && c > b) {
            if (a + b < c) {
                printf("C\n");
            }
            else {
                if (a > b) printf("A\n");
                else printf("B\n");
            }
        }
    }

    return 0;
}