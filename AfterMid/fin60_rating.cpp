#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int list[m];
    int popular[m];
    for (int i = 0; i < m; i++)
    {
        cin >> list[i];
        popular[i] = 0;
    }
    popular[0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 6; j > 0; j--)
        {
            if (i - j < 0)
            {
                continue;
            }
            if (list[i - j] == list[i])
            {
                popular[i] = popular[i - j] + 1;
            }
            if (popular[i] == 0)
            {
                popular[i] = 1;
            }
        }
    }
    int maxlist = 100001, maxrating = 0;
    for (int i = 0; i < m; i++)
    {
        if (popular[i] >= maxrating)
        {
            maxrating = popular[i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (popular[i] == maxrating)
        {
            if (list[i] < maxlist)
            {
                maxlist = list[i];
            }
        }
    }
    cout << maxlist << " " << maxrating << endl;
}