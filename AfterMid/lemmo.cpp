#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <vector>
#include <utility>

#define MAXN 120

using namespace std;

vector<pair<int, int>> flrlist;
char map[MAXN + 1][MAXN + 1];

int ans1 = 0, ans2 = 0;

int n, m;

bool stopDP = false;
bool visited[MAXN + 1][MAXN + 1];
int res[MAXN + 1][2];
struct Coor
{
    int first;
    int second;
    int drt;
};

Coor parent[2][MAXN + 1][MAXN + 1];
int dp[2][MAXN + 1][MAXN + 1];
int cnt[2][MAXN + 1][MAXN + 1];
int candidate[MAXN + 1][MAXN + 1];

Coor make_coor(int drt, int first, int second)
{
    Coor tmp;
    tmp.first = first;
    tmp.second = second;
    tmp.drt = drt;
    return tmp;
}

void reset(bool all)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
            if (all)
            {
                parent[0][i][j] = make_coor(-1, -1, -1);
                parent[1][i][j] = make_coor(-1, -1, -1);
            }
        }
    }
}

Coor backtrack(int drt, int ei, int ej, int res);

bool bfs(int si, int sj, int drt, char (&map)[MAXN + 1][MAXN + 1]);

bool bfs(int sj, int sdrt)
{
    return bfs(0, sj, sdrt, map);
}

bool bfs(int si, int sj, int sdrt)
{
    return bfs(si, sj, sdrt, map);
}

bool bfs(int sj, int sdrt, char (&map)[MAXN + 1][MAXN + 1])
{
    return bfs(0, sj, sdrt, map);
}

bool bfs(int si, int sj, int sdrt, char (&map)[MAXN + 1][MAXN + 1])
{
    reset(false);

    Coor v;
    list<Coor> Q;
    Q.push_back(make_coor(sdrt, si, sj));
    while (!Q.empty())
    {
        Coor u = Q.front();
        Q.pop_front();

        if (stopDP)
        {
            switch (dp[u.drt][u.first][u.second])
            {
            case 2:
                return true;
            case 1:
                continue;
            default:
                break;
            }
        }

        visited[u.first][u.second] = true;
        vector<Coor> adj;
        switch (map[u.first][u.second])
        {
        case '$':
            backtrack(u.drt, u.first, u.second, 2);
            return true;
        case '@':
            backtrack(u.drt, u.first, u.second, 1);
            continue;
        case '.':
            if (u.first + 1 < n)
                adj.push_back(make_coor(u.drt, u.first + 1, u.second));
            break;
        default:
            switch (u.drt)
            {
            case 0:
                if (u.second - 1 >= 0)
                    adj.push_back(make_coor(u.drt, u.first, u.second - 1));
                else
                {
                    adj.push_back(make_coor(1, u.first, u.second + 1));
                }
                break;
            case 1:
                if (u.second + 1 < m)
                    adj.push_back(make_coor(u.drt, u.first, u.second + 1));
                else
                {
                    adj.push_back(make_coor(0, u.first, u.second - 1));
                }
                break;
            }
        }

        int deg = adj.size();
        for (int i = 0; i < deg; i++)
        {
            v = adj[i];
            if (map[v.first][v.second] == '#')
            {
                if (v.second == m - 1 && v.drt == 1)
                {
                    v.drt = 0;
                }
                else if (v.second == 0 && v.drt == 0)
                {
                    v.drt = 1;
                }
            }

            if (v.first < n)
            {
                parent[v.drt][v.first][v.second].first = u.first;
                parent[v.drt][v.first][v.second].second = u.second;
                parent[v.drt][v.first][v.second].drt = u.drt;
                Q.push_back(v);
            }
        }
    }
    return false;
}

Coor backtrack(int drt, int ei, int ej, int res, bool findAns);

Coor backtrack(int drt, int ei, int ej, int res)
{
    return backtrack(drt, ei, ej, res, false);
}

Coor backtrack(int drt, int ei, int ej, int res, bool findAns)
{
    Coor tmp = parent[drt][ei][ej];
    int ni, nj, ndrt;
    int tick[2][MAXN + 1][MAXN + 1] = {};

    if (res != -1)
    {
        dp[drt][ei][ej] = res;
        cnt[drt][ei][ej]++;
        tick[drt][ei][ej] = 1;
    }

    while (tmp.first != -1 && tmp.second != -1)
    {
        ndrt = tmp.drt;
        ni = tmp.first;
        nj = tmp.second;

        if (res != -1)
        {
            dp[ndrt][ni][nj] = res;
            if (tick[ndrt][ni][nj] == 0)
            {
                cnt[ndrt][ni][nj]++;
                tick[ndrt][ni][nj] = 1;
            }
        }
        else if (findAns)
        {
            if (map[ni][nj] == '#' && ni + 1 < n && bfs(ni + 1, nj, ndrt))
                return make_coor(ndrt, ni, nj);
        }
        tmp = parent[tmp.drt][ni][nj];
    }
    return make_coor(-1, -1, -1);
}
void read_input()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", map[i]);
    }
}

int main()
{
    read_input();
    reset(true);

    vector<int> tunnelPos;
    int tmp = 0;
    for (int j = 0; j < m; j++)
    {
        tmp = 0;
        if (bfs(j, 0))
        {
            res[j][0] = 1;
            tmp++;
        }
        if (bfs(j, 1))
        {
            res[j][1] = 1;
            tmp++;
        }
        ans1 += tmp;

        if (map[n - 1][j] == '@')
            tunnelPos.push_back(j);
    }

    int tunnelN = tunnelPos.size();

    ans2 = ans1;
    stopDP = true;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != '#')
                continue;
            if (dp[0][i][j] == 2 && dp[1][i][j] == 2)
                continue;

            tmp = 0;
            if (dp[0][i][j] != 2 && ans1 + tmp + cnt[0][i][j] > ans2 && bfs(i + 1, j, 0))
                tmp += cnt[0][i][j];
            if (dp[1][i][j] != 2 && ans1 + tmp + cnt[1][i][j] > ans2 && bfs(i + 1, j, 1))
                tmp += cnt[1][i][j];
            if (ans1 + tmp > ans2)
                ans2 = ans1 + tmp;
        }
    }

    if (ans2 > m * 2)
        ans2 = m * 2;
    printf("%d %d", ans1, ans2);
    return 0;
}