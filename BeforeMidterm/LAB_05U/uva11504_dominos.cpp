#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int MAXM = 100100;

struct Edge
{
    int to;
    int next;
} edge[MAXM];

int dg[MAXN];
int n;
int m;
int Low[MAXN];
int DFN[MAXN];
int Stack[MAXN];
int Belong[MAXN];
int Index;
int top;
int scc;
bool Instack[MAXN];
int head[MAXN];
int tot;
int num[MAXN];

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void Tarjan(int u)
{
    int v;
    Index++;
    DFN[u] = Index;
    Low[u] = Index;
    Stack[top] = u;
    top++;
    Instack[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if (!DFN[v])
        {
            Tarjan(v);
            if (Low[u] > Low[v])
                Low[u] = Low[v];
        }
        else if (Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if (Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        } while (v != u);
    }
}

void solve()
{
    memset(Low, 0, sizeof(Low));
    memset(DFN, 0, sizeof(DFN));
    memset(num, 0, sizeof(num));
    memset(Stack, 0, sizeof(Stack));
    memset(Instack, false, sizeof(Instack));
    Index = 0;
    scc = 0;
    top = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!DFN[i])
        {
            Tarjan(i);
        }
    }
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        init();
        scanf("%d%d", &n, &m);
        int u, v;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            addedge(u, v);
        }
        solve();
        memset(dg, 0, sizeof(dg));
        for (int u = 1; u <= n; u++)
        {
            for (int i = head[u]; i != -1; i = edge[i].next)
            {
                int v = edge[i].to;
                if (Low[u] != Low[v])
                    dg[Belong[v]]++;
            }
        }
        int ans = 0;
        for (int i = 1; i <= scc; i++)
        {
            if (dg[i] == 0)
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
