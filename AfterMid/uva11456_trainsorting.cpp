#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename Comp>
void _LIS(const vector<int> &elements, vector<int> &out, Comp comp)
{
    out.assign(elements.size(), 1);
    for (int i = elements.size() - 1; i >= 0; --i)
    {
        for (int j = elements.size() - 1; j > i; --j)
        {
            if (comp(elements[j], elements[i]) && out[i] < out[j] + 1)
            {
                out[i] = out[j] + 1;
            }
        }
    }
}

int solve(const vector<int> &weights)
{
    vector<int> lis, lds;

    _LIS(weights, lis, less<int>());
    _LIS(weights, lds, greater<int>());

    int m = 0;
    for (size_t i = 0; i < weights.size(); ++i)
    {

        m = max(m, lis[i] + lds[i] - 1);
    }
    return m;
}

int main()
{
    int nCases;
    cin >> nCases;

    while (nCases--)
    {
        int nCars;
        cin >> nCars;

        vector<int> weights(nCars);
        for (int i = 0; i < nCars; ++i)
        {
            cin >> weights[i];
        }

        cout << solve(weights) << endl;
    }
    return 0;
}
