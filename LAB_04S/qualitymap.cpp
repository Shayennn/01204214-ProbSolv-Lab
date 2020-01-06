#include <cstdio>
#include <list>

using namespace std;

#define MAX_N  30
#define MAX_M  30

int n, m;

int lv1 = 0, lv2 = 0;
bool explored[MAX_N][MAX_M];
int map[MAX_N][MAX_M];

void init(){
    for(int i=0;i<MAX_N;i++){
        for(int j=0;j<MAX_M;j++){
            if(i<n && i<m)explored[i][j] = false;
            else explored[i][j] = true;
        }
    }
}

void explore(int i, int j){
    if(map[i][j] == -1)return;
    int x, y, counter1 = 0, counter2 = 0, area = 0;
    list<int> Q1;
    list<int> Q2;
    Q1.push_back(i);
    Q2.push_back(j);
    explored[i][j] = true;
    if(map[i][j] == 1)++counter1;
    if(map[i][j] == 2)++counter2;
    ++area;

    while(!Q1.empty()){
        x = Q1.front();Q1.pop_front();
        y = Q2.front();Q2.pop_front();

        if(x-1 >= 0 && x-1 < n && !explored[x-1][y]){
            if(map[x-1][y] >= 0){
                Q1.push_back(x-1);
                Q2.push_back(y);
                explored[x-1][y] = true;
                if(map[x-1][y] == 1)++counter1;
                if(map[x-1][y] == 2)++counter2;
                ++area;
            }
        }
        if(x+1 >= 0 && x+1 < n && !explored[x+1][y]){
            if(map[x+1][y] >= 0){
                Q1.push_back(x+1);
                Q2.push_back(y);
                explored[x+1][y] = true;
                if(map[x+1][y] == 1)++counter1;
                if(map[x+1][y] == 2)++counter2;
                ++area;
            }
        }
        if(y-1 >= 0 && y-1 < m && !explored[x][y-1]){
            if(map[x][y-1] >= 0){
                Q1.push_back(x);
                Q2.push_back(y-1);
                explored[x][y-1] = true;
                if(map[x][y-1] == 1)++counter1;
                if(map[x][y-1] == 2)++counter2;
                ++area;
            }
        }
        if(y+1 >= 0 && y+1 < m && !explored[x][y+1]){
            if(map[x][y+1] >= 0){
                Q1.push_back(x);
                Q2.push_back(y+1);
                explored[x][y+1] = true;
                if(map[x][y+1] == 1)++counter1;
                if(map[x][y+1] == 2)++counter2;
                ++area;
            }
        }
    }
    if(counter1 > 0 && counter2 > 0)lv2+=area;
    else if(counter1 > 0 || counter2 > 0)lv1+=area;
}

int main(){
    char tmp;
    scanf("%d %d", &n, &m);
    init();
    for(int i=0;i<n;i++){
        scanf("\n");
        for(int j=0;j<m;j++){
            scanf("%c", &tmp);
            if(tmp == '.')map[i][j] = 0;
            else if(tmp == '*')map[i][j] = 1;
            else if(tmp == '$')map[i][j] = 2;
            else if(tmp == '#')map[i][j] = -1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!explored[i][j]){
                explore(i, j);
            }
        }
    }
    printf("%d %d\n", lv2, lv1);
    return 0;
}
