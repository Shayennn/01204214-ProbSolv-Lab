#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long int> v;

int main()
{
    int n, s, e, j, k;
    long long int p, q, ans = 0;

    scanf("%d %lld %lld", &n, &p, &q);

    for (int i = 0; i < n; i++)
    {
        long long int c;
        scanf("%lld", &c);
        v.push_back(c);
    }

    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++)
    {
        s = 0;
        e = i - 1;
        j = -1;
        while (s <= e)
        {
            int mid = (s + e) / 2;

            if (v[i] + v[mid] == q)
            {
                j = mid;
                s = mid + 1;
            }
            else if (v[i] + v[mid] < q)
            {
                j = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }

        printf("j %d ", j + 1);

        s = 0;
        e = i - 1;
        k = -1;

        while (s <= e)
        {
            int mid = (s + e) / 2;

            if (v[i] + v[mid] == p)
            {
                e = mid - 1;
            }
            else if (v[i] + v[mid] < p)
            {
                k = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        printf("k %d\n", k + 1);
        ans += j - k;
    }
    printf("%lld", ans);
}