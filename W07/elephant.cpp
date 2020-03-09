#include <stdio.h>

#define FUCKIN_MAX 100010

int fuck_score[FUCKIN_MAX];
int fuck_sum_max[FUCKIN_MAX];
int fuck_n;

int main()
{
    scanf("%d", &fuck_n);
    for (int i = 0; i < fuck_n; i++)
    {
        scanf("%d", &fuck_score[i]);
        if (i <= 1)
        {
            fuck_score[i] = 0;
            continue;
        }
        if (i == 2){
            fuck_sum_max[i] = fuck_score[i];
        }
        if (i >= 3) {
            if(fuck_sum_max[i-1] > fuck_score[i] + fuck_sum_max[i-3]){
                fuck_sum_max[i] = fuck_sum_max[i-1];
            } else {
                fuck_sum_max[i] = fuck_score[i] + fuck_sum_max[i-3];
            }
        }
    }
    printf("%d\n",fuck_sum_max[fuck_n-1]);
    return 0;
}