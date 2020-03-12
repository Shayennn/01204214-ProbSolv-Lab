#include <cstdio>
#include <set>

using namespace std;

int n;
int q;
int pole[1001];

set<int> aaa;

void connect(int i, int now)
{
    if (i >= n) return;

    aaa.insert(pole[i] + now);
    connect(1 + i, pole[i] + now);
    aaa.insert(now);
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pole[i]);
    }

    for (int i = 0; i < n; i++)
    {
        connect(i, 0);
    }

    int inp;

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &inp);
        if (aaa.count(inp) != 0) printf("Y");
        else printf("N");
    }
    return 0;
}