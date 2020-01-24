#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*((int *)a) - *((int *)b));
}

int main()
{
    int works[100000][2];
    int N, C, D, i, max_late = 0, daycount = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &works[i][0], &works[i][1]);
    }
    qsort(works, N, sizeof(int) * 2, compare);
    for (i = 0; i < N; i++)
    {
        // printf("%d->%d\n", works[i][0], works[i][1]);
        daycount += works[i][1];
        if (daycount > works[i][0] + 10)
        {
            if (daycount - (works[i][0] + 10) > max_late)
                max_late = daycount - (works[i][0] + 10);
        }
    }
    printf("%d", max_late * 1000);
    return 0;
}