#include <stdio.h>

int main()
{
    int m[] = {1, 5, 10, 25, 50};
    int i, j;
    long long DP[30001] = {};

    DP[0] = 1;

    for (i = 0; i < 5; i++)
    {
        for (j = m[i]; j <= 30000; j++)
        {
            DP[j] += DP[j - m[i]];
        }
    }

    while (scanf("%d", &i) == 1)
    {
        if (DP[i] != 1)
            printf("There are %lld ways to produce %d cents change.\n", DP[i], i);
        else
            printf("There is only 1 way to produce %d cents change.\n", i);
    }
    return 0;
}