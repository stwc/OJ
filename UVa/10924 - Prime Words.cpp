// "a" is regarded as prime word for this question.

#include <bits/stdc++.h>
using namespace std;

#define MAX 1100

bool prime[MAX];

void table()
{
    for (int i = 0; i < MAX; ++i) prime[i] = true;
    prime[0] = false;
    for (int i = 2; i < sqrt(MAX); ++i) {
        if (prime[i])
            for (int j = 2; i * j < MAX; ++j)
                prime[i*j] = false;
    }
}

int main()
{
    table();
    string line;
    while (getline(cin, line)) {
        int sum = 0;
        for (int i = 0; i < line.size(); ++i) {
            if (islower(line[i]))
                sum += (line[i] - 'a' + 1);
            else
                sum += (line[i] - 'A' + 27);
        }

        if (prime[sum]) cout << "It is a prime word.\n";
        else cout << "It is not a prime word.\n";
    }
    return 0;
}