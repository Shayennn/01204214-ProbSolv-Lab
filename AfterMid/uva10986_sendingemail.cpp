#include <iostream>
#include <map>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

struct Cable
{
    int u, v;
    int latency;

    bool operator>(const Cable &c) const
    {
        return this->latency > c.latency;
    }
};

int main()
{
    int Case = 1;
    int N;
    cin >> N;
    while (N--)
    {
        map<int, int> dist;
        map<int, vector<Cable>> cables;
        int n, m, S, T;

        cin >> n >> m >> S >> T;
        for (int i = 0; i < m; ++i)
        {
            Cable cable;
            cin >> cable.u >> cable.v >> cable.latency;
            cables[cable.u].push_back(cable);
            swap(cable.u, cable.v);
            cables[cable.u].push_back(cable);
        }

        priority_queue<Cable, vector<Cable>, greater<Cable>> pq;

        Cable s;
        s.latency = 0;
        s.v = S;
        s.u = S;
        pq.push(s);
        dist[S] = 0;
        while (!pq.empty())
        {
            Cable e1 = pq.top();
            pq.pop();

            if (dist[e1.u] + e1.latency > dist[e1.v])
                continue;
            for (size_t i = 0; i < cables[e1.v].size(); ++i)
            {
                Cable e2 = cables[e1.v][i];

                if (!dist.count(e2.v) || dist[e2.u] + e2.latency < dist[e2.v])
                {
                    dist[e2.v] = dist[e2.u] + e2.latency;
                    pq.push(e2);
                }
            }
        }
        cout << "Case #"
             << Case++
             << ": ";
        if (dist.count(T))
            cout << dist[T] << endl;
        else
            cout << "unreachable" << endl;
    }
    return 0;
}