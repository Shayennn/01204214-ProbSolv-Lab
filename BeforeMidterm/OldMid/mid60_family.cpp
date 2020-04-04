#include <stdio.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int parent[n + 1];
    parent[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        scanf("%d", &parent[i]);
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        if (a == 1 || b == 1)
        {
            printf("1\n");
        }
        else if (parent[a] == b)
        {
            printf("%d\n", b);
        }
        else if (parent[b] == a)
        {
            printf("%d\n", a);
        }
        else
        {
            int x = -1;
            bool found = false;
            x = parent[a];
            while (!found && x != 1)
            {
                if (x == b)
                {
                    found = true;
                    printf("%d\n", x);
                    break;
                }
                else
                {
                    int tmp = x;
                    x = parent[tmp];
                }
            }
            if (!found)
            {
                x = parent[b];
                while (!found && x != 1)
                {
                    if (x == a)
                    {
                        found = true;
                        printf("%d\n", x);
                        break;
                    }
                    else
                    {
                        int tmp = x;
                        x = parent[tmp];
                    }
                }
            }
            if (!found)
            {
                printf("-1\n");
            }
        }
    }
}