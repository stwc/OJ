#include <stdio.h>

int cycle(int n)
{
    int count = 1;
    while (n != 1) {
        if (n % 2 == 1) n = 3 * n + 1;
        else n = n / 2;
        count++;
    }
    return count;
}

int main()
{
    int i, j, oi, oj, temp, k, n, max;
    
    while (scanf("%d %d", &i, &j) == 2) {
        oi = i;
        oj = j;
        max = 0;
        
        if (i > j) {
            temp = i;
            i = j;
            j = temp;
        }

        for (n = i; n <= j; n++) {
            k = cycle(n);
            if (k > max) max = k;
        }

        printf("%d %d %d\n", oi, oj, max);
    }
    return 0;
}