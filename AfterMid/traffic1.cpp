#include "traffic.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, k;

int mindist(int x1, int y1, int x2, int y2)
{
    int res = 0;
    res += abs(x2 - x1);
    res += abs(y2 - y1);
    return res;
}

int main()
{
    traffic_init(&n, &k);
    int mid, lo, hi;
    for (int x = 1; x <= n; x++)
    {
        if (traffic_query(x, n, x, 1) > n - 1)
        {
            lo = n;
            hi = 1;
            while (true)
            {
                mid = floor((lo + hi) / 2);
                if (traffic_query(x, mid - 1, x, mid) == 2)
                {
                    traffic_report(x, mid - 1, x, mid, 0, 0, 0, 0);
                }
                else if (traffic_query(x, mid, x, mid + 1) == 2)
                {
                    traffic_report(x, mid, x, mid + 1, 0, 0, 0, 0);
                }
                else if (traffic_query(x, lo, x, mid) > abs(lo - mid))
                {
                    hi = mid;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            break;
        }
    }
    for (int y = 1; y <= n; y++)
    {
        if (traffic_query(1, y, n, y) > n - 1)
        {
            lo = 1;
            hi = n;
            while (true)
            {
                mid = floor((lo + hi) / 2);
                if (traffic_query(mid - 1, y, mid, y) == 2)
                {
                    traffic_report(mid - 1, y, mid, y, 0, 0, 0, 0);
                }
                else if (traffic_query(mid, y, mid + 1, y) == 2)
                {
                    traffic_report(mid, y, mid + 1, y, 0, 0, 0, 0);
                }
                else if (traffic_query(lo, y, mid, y) > abs(lo - mid))
                {
                    hi = mid;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            break;
        }
    }
}
