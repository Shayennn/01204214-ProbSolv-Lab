#include <stdio.h>

int people[5000], give_sum[5000];

int N, K;

int food_give(int food, int index)
{
    if (index == N)
    {
        return 0;
    }
    if (give_sum[index] == -1)
    {
        give_sum[index] = food_give(K, index + 1);
    }
    if (people[index] > food)
    {
        return give_sum[index];
    }
    int total_give = people[index] + food_give(food - people[index], index + 1);
    if (give_sum[index] > total_give)
        return give_sum[index];
    return total_give;
}

int main()
{
    int total = 0;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &people[i]);
        total += people[i];
        give_sum[i] = -1;
    }

    printf("%d", total - food_give(K, 0));

    return 0;
}
