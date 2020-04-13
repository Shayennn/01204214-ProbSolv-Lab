#include <stdio.h>

int levels[100005];
int levels_force[100005];
int level_sums[100005];

int max_lv;

bool forcecheck(int from, int level)
{
    bool result = false;
    for (int i = 1; i < level; i++)
    {
        result |= (levels_force[from + i]);
    }
    return result;
}

void checkBefore(int i)
{
    max_lv = level_sums[i - 1];
    if (!forcecheck(i - 4, 4) && level_sums[i - 4] > max_lv)
    {
        // printf("4\n");
        max_lv = level_sums[i - 4];
    }
    if (!forcecheck(i - 3, 3) && level_sums[i - 3] > max_lv)
    {
        // printf("3\n");
        max_lv = level_sums[i - 3];
    }
    if (!forcecheck(i - 2, 2) && level_sums[i - 2] > max_lv)
    {
        // printf("2\n");
        max_lv = level_sums[i - 2];
    }
    level_sums[i] += max_lv;
}

int main()
{
    int i, N, cond;
    scanf("%d", &N);
    levels_force[0] = levels[0] = level_sums[0] = 0;
    levels_force[1] = levels[1] = level_sums[1] = 0;
    levels_force[2] = levels[2] = level_sums[2] = 0;
    levels[3] = level_sums[3] = 0;
    levels_force[3] = 1;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &level_sums[4 + i]);
        levels[4 + i] = level_sums[4 + i];
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", &levels_force[4 + i]);
        checkBefore(4 + i);
    }
    levels[N + 4] = 0;
    level_sums[N + 4] = 0;
    checkBefore(N + 4);
    printf("%d", level_sums[N + 4]);
    return 0;
}
