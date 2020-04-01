#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100010

int n, m;
int parent[MAX_N];

void init()
{
    for (int i = 0; i < n + 1; i++)
    {
        parent[i] = i;
    }
}

int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void Union(int x, int y)
{
    int x_parent = find(x);
    int y_parent = find(y);
    parent[x_parent] = y_parent;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    init();
    char order;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> order >> a >> b;
        if (order == 'c')
        {
            Union(a, b);
        }
        else if (order == 'q')
        {
            int parent_a = find(a);
            int parent_b = find(b);
            if (parent_a == parent_b)
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }
}