#include <cstdio>
#include <vector>
#include <list>


using namespace std;

#define MAX_N  100000

int n,m;

vector<int> adj[MAX_N];
int deg[MAX_N];
bool explored[MAX_N];
int levels[MAX_N];

void read_input()
{
  scanf("%d %d",&n,&m);
  for(int i=0; i<n; i++) {
    deg[i] = 0;
  }
  for(int i=0; i<m; i++) {
    int u,v;
    scanf("%d %d",&u,&v); u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

bool visited[MAX_N];

void init()
{
  for(int i=0; i<n; i++)
    visited[i] = false;
}

void dfs(int u)
{
  visited[u] = true;
  for(int i=0; i<deg[u]; i++) {
    int v = adj[u][i];
    if(!visited[v]) {
      dfs(v);
    }
  }
}

void bfs(int s)
{
  explored[s] = true;
  levels[s] = 0;
  list<int> Q;
  Q.push_back(s);

  while(!Q.empty()) {
    int u = Q.front();
    Q.pop_front();

    for(int i=0; i<deg[u]; i++) {
      int v = adj[u][i];

      if(!explored[v]) {
        explored[v] = true;
        levels[v] = levels[u] + 1;
        Q.push_back(v);        
      }
    }
  }
}

int main(){
    read_input();
    init();
    int groupcount=0;
    for(int i=0;i<n;i++){
        if(!explored[i]){
            bfs(i);
            ++groupcount;
        }
    }
    printf("%d\n", groupcount);
    return 0;
}