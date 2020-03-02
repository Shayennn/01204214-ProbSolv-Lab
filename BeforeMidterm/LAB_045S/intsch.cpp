#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*((int *)a+1) - *((int *)b+1));
}

int main()
{
    int intervals[100000][2];
    int N, C, D, i, timecount = 0, count_interval = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }
    qsort(intervals, N, sizeof(int) * 2, compare);
    for (i = 0; i < N; i++)
    {
        if(intervals[i][0] < timecount){
            continue;
        } else {
            count_interval++;
        }
        timecount = intervals[i][1];
    }
    printf("%d", count_interval);
    return 0;
}