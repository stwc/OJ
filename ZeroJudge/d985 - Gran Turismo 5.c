#include <stdio.h>

void sorting(int arr[], int m);

int main()
{
    int n, m;
    int arr[101];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            int a, b;
            scanf("%d %d", &a, &b);
            arr[j] = a * 60 + b;
        }

        sorting(arr, m);
        int avg = 0;
        for (int j = 0; j < m; ++j) {
            avg += arr[j];
        }
        avg /= m;

        printf("Track %d:\n", i + 1);
        printf("Best Lap: %d minute(s) %d second(s).\n", arr[0] / 60, arr[0] % 60);
        printf("Average: %d minute(s) %d second(s).\n", avg / 60, avg % 60);
    }
    return 0;
}

void sorting(int arr[], int m)
{
    int j;
    for (int i = 0; i < m - 1; ++i) {
        int min = i;
        for (j = i + 1; j < m; ++j) {
            if (arr[min] > arr[j]) 
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}