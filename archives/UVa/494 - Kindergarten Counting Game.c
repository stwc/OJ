#include <stdio.h>

int main()
{
    char line[1001];
    
    while (gets(line)) {
        int i, count = 0, isword = 0;

        for (i = 0; line[i]; i++) {
            if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
                isword = 1;
            else {
                count += isword;
                isword = 0;
            }
        }
        // If the last character is a letter.
        count += isword;
        printf("%d\n", count);
    }
    return 0;    
}