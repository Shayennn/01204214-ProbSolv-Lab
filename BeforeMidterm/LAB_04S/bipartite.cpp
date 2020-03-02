#include <cstdio>
#include <vector>
#include <list>


using namespace std;

#define MAX_N  100000

int n,m;

vector<int> adj[MAX_N];
int deg[MAX_N];
bool visited[MAX_N];
int levels[MAX_N];

void read_input()
{
  scanf("%d %d",&n,&m);
  for(int i=0; i<n; i++) {
    deg[i] = 0;
    adj[i].clear();
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

void init()
{
  for(int i=0; i<n; i++)
    visited[i] = false;
}

bool bfs(int s)
{
  visited[s] = true;
  levels[s] = 0;
  list<int> Q;
  Q.push_back(s);

  while(!Q.empty()) {
    int u = Q.front();
    Q.pop_front();

    for(int i=0; i<deg[u]; i++) {
      int v = adj[u][i];

      if(!visited[v]) {
        visited[v] = true;
        levels[v] = levels[u] + 1;
        Q.push_back(v);        
      } else {
          if(levels[u] == levels[v]){
            //   printf("Mom(%d): %d Child(%d): %d\n", u+1, levels[u], v+1,levels[v]);
              return false;
          }
      }
    }
  }
  return true;
}

int main(){
    int g;
    bool result;
    scanf("%d", &g);
    for(int i=0;i<g;i++){
        result = true;
        read_input();
        init();
        for(int j=0; j<n; j++){
            if(visited[j])continue;
            // printf("i: %d j:%d\n", i, j);
            if(!bfs(j)){
                result = false;
                break;
            }
        }
        if(result)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}