#include <cstdio>
#include <map>

using namespace std;

int n;
int mval = 0;

map<int, int> buy, sell;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    scanf("%d", &n);
    int type, limit, amt;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &type, &limit, &amt);
        switch (type)
        {
        case 1:
            while (sell.begin() != sell.end() && sell.begin()->first <= limit && amt > 0)
            {
                if (sell.begin()->second > amt)
                {
                    mval += limit * amt;
                    sell.begin()->second -= amt;
                    if (sell.begin()->second == 0)
                        sell.erase(sell.begin());
                    amt = 0;
                }
                else
                {
                    mval += limit * sell.begin()->second;
                    amt -= sell.begin()->second;
                    sell.erase(sell.begin());
                }
            }
            if (amt > 0)
            {
                if (!buy.count(limit))
                    buy[limit] = 0;
                buy[limit] += amt;
            }
            break;
        case 2:
            for (map<int, int>::reverse_iterator it = buy.rbegin(); amt > 0 && it != buy.rend() && it->first >= limit;)
            {
                if (it->second <= 0)
                {
                    ++it;
                    continue;
                }

                if (amt < it->second)
                {
                    mval += limit * amt;
                    it->second -= amt;
                    amt = 0;
                    break;
                }
                else
                {
                    mval += limit * it->second;
                    amt -= it->second;
                    it->second = 0;
                    //buy.erase(it++);
                }
            }
            if (amt > 0)
            {
                if (!sell.count(limit))
                    sell[limit] = 0;
                sell[limit] += amt;
            }
            break;
        }
    }
    printf("%d", mval);
    return 0;
}