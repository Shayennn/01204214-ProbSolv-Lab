#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, m, test, score, sum = 0;
    cin >> n >> m;
    int keepScore[n];
    int cnt[n];

    for (int i = 0; i < n; i++)
    {
        keepScore[i] = 0;
        cnt[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> test >> score;
        cnt[test - 1]++;
        if (cnt[test - 1] > 5)
        {
            keepScore[test - 1] = 0;
        }
        else
        {
            if (score > keepScore[test - 1])
            {
                keepScore[test - 1] = score;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum += keepScore[i];
    }
    cout << sum << endl;
}
