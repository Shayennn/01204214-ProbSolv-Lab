#include <cstdio>
#include <vector>
#include <list>

using namespace std;

#define MAX_M 3000

int n, m;
int skip_u = -1, skip_v = -1;

vector<int> adj[MAX_M];
int deg[MAX_M];
bool visited[MAX_M];
int levels[MAX_M];

int pairs[MAX_M][2];

void read_input()
{
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    deg[i] = 0;
    adj[i].clear();
  }
  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    pairs[i][0] = u;
    pairs[i][1] = v;
    // printf("%d %d\n",u+1,v+1);
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

void init()
{
  for (int i = 0; i < n; i++)
    visited[i] = false;
}

bool bfs(int s)
{
  visited[s] = true;
  levels[s] = 0;
  list<int> Q;
  Q.push_back(s);

  while (!Q.empty())
  {
    int u = Q.front();
    Q.pop_front();

    for (int i = 0; i < deg[u]; i++)
    {
      int v = adj[u][i];

      if((u == skip_u && v == skip_v) || (v == skip_u && u == skip_v))continue;

      if (!visited[v])
      {
        visited[v] = true;
        levels[v] = levels[u] + 1;
        Q.push_back(v);
      }
      else
      {
        if (levels[u] == levels[v])
        {
          // printf("%d %d\n", u + 1, v + 1);
          // printf("Mom(%d): %d Child(%d): %d\n", u+1, levels[u], v+1,levels[v]);
          return false;
        }
      }
    }
  }
  return true;
}

int main()
{
  bool result;
  read_input();
  for (int i = -1; i < m; i++)
  {
    result = true;
    if(i != -1){
      skip_u = pairs[i][0];
      skip_v = pairs[i][1];
    }
    // printf("Try %d %d\n", skip_u+1, skip_v+1);
    init();
    for (int j = 0; j < n; j++)
    {
      if (visited[j])
        continue;
      // printf("i: %d j:%d\n", i, j);
      if (!bfs(j))
      {
        result = false;
        break;
      }
    }
    if(result && i != -1){
      printf("%d %d", skip_u+1, skip_v+1);
      break;
    }
  }
  // if(result)printf("yes\n");
  // else printf("no\n");
  return 0;
}