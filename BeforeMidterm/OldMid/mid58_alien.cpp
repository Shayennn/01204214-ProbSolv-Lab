#include <cstdio>
#include <cmath>
int main()
{
    int n;
    int a;
    int b;
    int r;

    scanf("%d %d %d %d", &n, &a, &b, &r);
    int ans = 0;
    int tmp;
    int x;
    int y;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        tmp = pow(y - b, 2) + pow(x - a, 2);
        if (tmp <= r * r) ++ans;
    }
    printf("%d", ans);
    return 0;
}