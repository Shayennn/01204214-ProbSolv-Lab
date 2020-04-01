#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int x[100100], y[100100];
    int cost_x[100100], cost_y[100100];
    int a[100100], b[100100];
    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        x[0] = a[0];
        cost_x[0] = 1;
        y[0] = b[0];
        cost_y[0] = -1;
        for (int i = 1; i < n; i++)
        {
            if (abs(cost_x[i - 1] + 1) <= k)
            {
                if (x[i - 1] < y[i - 1])
                {
                    x[i] = x[i - 1] + a[i];
                    cost_x[i] = cost_x[i - 1] + 1;
                }
                else
                {
                    x[i] = y[i - 1] + a[i];
                    cost_x[i] = cost_y[i - 1] + 1;
                }
            }
            else
            {
                x[i] = y[i - 1] + a[i];
                cost_x[i] = cost_y[i - 1] + 1;
            }

            if (abs(cost_y[i - 1] - 1) <= k)
            {
                if (x[i - 1] > y[i - 1])
                {
                    y[i] = y[i - 1] + b[i];
                    cost_y[i] = cost_y[i - 1] - 1;
                }
                else
                {
                    y[i] = x[i - 1] + b[i];
                    cost_y[i] = cost_x[i - 1] - 1;
                }
            }
            else
            {
                y[i] = x[i - 1] + b[i];
                cost_y[i] = cost_x[i - 1] - 1;
            }
        }
        int ans = (x[n - 1] < y[n - 1]) ? x[n - 1] : y[n - 1];
        cout << ans << '\n';
    }
}