#include <cstdio>
#include <list>

using namespace std;

#define MAX_N  30
#define MAX_M  30

int n, m;

int lv1 = 0, lv2 = 0;
bool explored[MAX_N][MAX_M];
bool map[MAX_N][MAX_M];

void init(){
    for(int i=0;i<MAX_N;i++){
        for(int j=0;j<MAX_M;j++){
            if(i<n && i<m)explored[i][j] = false;
            else explored[i][j] = true;
        }
    }
}

bool isFit(int i, int j){
    bool cond = true;
    cond &= map[i][j];
    cond &= map[i+1][j];
    cond &= map[i][j+1];
    cond &= map[i+1][j+1];
    cond &= i+1 < n;
    cond &= j+1 < m;
    return cond;
}

bool isExplore(int i, int j){
    bool cond = true;
    cond &= explored[i][j];
    // cond &= explored[i+1][j];
    // cond &= explored[i][j+1];
    // cond &= explored[i+1][j+1];
    // cond &= i < m;
    // cond &= j < n;
    return cond;
}

void setExplore(int i, int j){
    explored[i][j] = true;
    // explored[i+1][j] = true;
    // explored[i][j+1] = true;
    // explored[i+1][j+1] = true;
}

bool explore(int i, int j){
    if(!isFit(i, j)) return false;
    // printf(">> %d %d\n", i, j);
    int x, y;
    list<int> Q1;
    list<int> Q2;
    Q1.push_back(i);
    Q2.push_back(j);

    while(!Q1.empty()){
        x = Q1.front();Q1.pop_front();
        y = Q2.front();Q2.pop_front();
        setExplore(x, y);
        // printf("%d %d\n", x, y);
        if(x+2 == n){
            printf("yes\n");
            return true;
        }

        if(x-1 >= 0 && x-1 < n && !isExplore(x-1, y)){
            if(isFit(x-1, y)){
                Q1.push_back(x-1);
                Q2.push_back(y);
            }else{
                // printf("NOT FIT %d %d\n", x-1, y);
            }
        }
        if(x+1 >= 0 && x+1 < n && !isExplore(x+1, y)){
            if(isFit(x+1, y)){
                Q1.push_back(x+1);
                Q2.push_back(y);
            }else{
                // printf("NOT FIT %d %d\n", x+1, y);
            }
        }
        if(y-1 >= 0 && y-1 < m && !isExplore(x, y-1)){
            if(isFit(x, y-1)){
                Q1.push_back(x);
                Q2.push_back(y-1);
            }else{
                // printf("NOT FIT %d %d\n", x, y-1);
            }
        }
        if(y+1 >= 0 && y+1 < m && !isExplore(x, y+1)){
            if(isFit(x, y+1)){
                Q1.push_back(x);
                Q2.push_back(y+1);
            }else{
                // printf("NOT FIT %d %d\n", x, y+1);
            }
        }
    }
    return false;
}

int main(){
    char tmp;
    scanf("%d %d", &n, &m);
    init();
    for(int i=0;i<n;i++){
        scanf("\n");
        for(int j=0;j<m;j++){
            scanf("%c", &tmp);
            if(tmp == '.')map[i][j] = true;
            else if(tmp == '#')map[i][j] = false;
        }
    }
    for(int i=0;i<m-1;i++){
        if(!explored[0][i]){
            if(explore(0, i)) return 0;
        }
    }
    printf("no\n");
    return 0;
}
