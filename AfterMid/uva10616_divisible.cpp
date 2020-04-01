#include <cstdio>
#include <cstring>
typedef long long ll;

ll dp[205][15][25];
int d, m, n, arr[205];

ll f(int i, int cnt, ll sum)
{
    if (cnt == m)
        return dp[i][cnt][sum] = (sum % d ? 0 : 1);
    if (i == n)
        return dp[i][cnt][sum] = 0;
    if (dp[i][cnt][sum] >= 0)
        return dp[i][cnt][sum];
    return dp[i][cnt][sum] = f(i + 1, cnt + 1, ((sum + arr[i]) % d + d) % d) + f(i + 1, cnt, sum);
}

int main()
{
    int cas = 0, q, i, ans;
    while (scanf("%d%d", &n, &q), n)
    {
        for (i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        printf("SET %d:\n", ++cas);
        for (i = 1; i <= q; ++i)
        {
            ans = 0;
            memset(dp, -1, sizeof(dp));
            scanf("%d%d", &d, &m);
            printf("QUERY %d: %d\n", i, f(0, 0, 0));
        }
    }
    return 0;
}
