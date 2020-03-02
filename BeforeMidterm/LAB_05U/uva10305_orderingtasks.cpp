#include <cstdio>
#include <list>

using namespace std;

list<int> result;
bool conds[100][100];
int in_edge_count[100];
int n, m;

void clearConds(){
    for(int i=0; i<n;i++){
        for (int j = 0; j < n; j++)conds[i][j] = false;
        in_edge_count[i] = 0;
    }
}

int main(){
    int a, b, a_node_n;
    list<int> S;

    while(true){
        scanf("%d %d", &n, &m);
        if(n==m && n == 0)break;
        clearConds();
        S.clear();
        result.clear();

        for(int i = 0; i<m; i++){
            scanf("%d %d", &a, &b);
            if(!conds[a-1][b-1]){
                conds[a-1][b-1] = true;
                ++in_edge_count[b-1];
            }
        }

        for(int i = 0; i<n; i++){
            if(in_edge_count[i] == 0)S.push_back(i);
        }

/*
L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edge

while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S

if graph has edges then
    return error   (graph has at least one cycle)
else 
    return L   (a topologically sorted order)
*/

        while(!S.empty()){
            a_node_n = S.front();
            S.pop_front();
            result.push_back(a_node_n);

            for(int i = 0; i<n; i++){
                if(!conds[a_node_n][i])continue;
                conds[a_node_n][i] = false;
                --in_edge_count[i];
                // printf("%d->%d: %d\n", a_node_n+1, i+1, in_edge_count[i]);
                if(in_edge_count[i] == 0){
                    S.push_back(i);
                }
            }
        }

        printf("%d", result.front()+1);
        result.pop_front();
        while(!result.empty()){
            printf(" %d", result.front()+1);
            result.pop_front();
        }
        printf("\n");
    }

    return 0;
}