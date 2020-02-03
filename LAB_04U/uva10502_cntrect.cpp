#include <stdio.h>

int main()
{
    char map[101][101];
    int n, m, i, j, k;
    while (scanf("%d", &n) == 1 && n)
    {
        scanf("%d", &m);
        for (i = 0; i < n; i++)
        {
            scanf("%s", &map[i]);
        }
        int counter = 0, width, length, temp;
        for (i = 0; i < n; i++)
        {
            int sum[101] = {};
            for (j = i; j < n; j++)
            {
                for (k = 0; k < m; k++)
                {
                    sum[k] += map[j][k] - '0';
                    if (temp!= width * length || k == 0)
                    {
                        temp = 0;
                        length = 0;
                    }
                    length++;
                    width = j - i + 1;
                    temp+= sum[k];
                    if (temp== width * length)
                    {
                        counter += length;
                    }
                }
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}