#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct shop
{
    int pos;
    int price;
    int amt;
};

int n;
int q;
map<int, shop> shidx;
int home;

bool sortme(shop a, shop b)
{
    return a.price < b.price && abs(a.pos - home) <= 5 && abs(b.pos - home) > 5;
}
bool sortidx(int a, int b)
{
    return shidx[a].price < shidx[b].price;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        shop newsh;
        scanf("%d %d %d", &newsh.pos, &newsh.price, &newsh.amt);
        if (newsh.amt != 0)
        {
            shidx[newsh.pos] = newsh;
        }
    }
    int cost;
    for (int qq = 0; qq < q; qq++)
    {
        scanf("%d", &home);
        cost = 0;
        vector<int> cand;
        for (int i = max(1, home - 5); i <= min(home + 5, 1000000000); i++)
        {
            if (shidx.count(i) && shidx[i].amt > 0)
            {
                cand.push_back(i);
            }
        }
        if (!cand.empty())
        {
            sort(cand.begin(), cand.end(), sortidx);
            cost = shidx[cand[0]].price;
            shidx[cand[0]].amt--;
        }
        printf("%d\n", cost);
    }
    return 0;
}