#include <stdio.h>
#define MAX 25
#define SEEN 's'

int N;
int M;
int X;
int Y;
char g[MAX][MAX];
int v[MAX][MAX];
char land;
int ans;

int floodfill(int x, int y)
{
    int ret;
    if (y == M)
        y = 0;
    else if (y == -1)
        y = M - 1;
    if (x < 0 || x >= N || y < 0 || y >= M)
        return 0;
    if (v[x][y])
        return 0;
    if (g[x][y] != land)
        return 0;

    v[x][y] = 1;
    ret = 1;
    ret += floodfill(x, y - 1);
    ret += floodfill(x, y + 1);
    ret += floodfill(x + 1, y);
    ret += floodfill(x - 1, y);
    return ret;
}

int main()
{
    int i, j, t;
    while (scanf("%d %d", &N, &M) == 2)
    {
        getchar();
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                g[i][j] = getchar();
                v[i][j] = 0;
            }
            getchar();
        }
        scanf("%d %d", &X, &Y);
        land = g[X][Y];
        floodfill(X, Y);
        ans = 0;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                if (g[i][j] == land)
                {
                    t = floodfill(i, j);
                    if (t > ans)
                        ans = t;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}