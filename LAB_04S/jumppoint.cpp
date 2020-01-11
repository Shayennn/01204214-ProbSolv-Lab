#include <cstdio>
#include <list>
#include <math.h>

using namespace std;

struct pos
{
    int x;
    int y;
    bool explored {false};
};

list<int> connected[1002];
pos points[1002];
int N, R2;

int explore(){
    int levels[1002];
    int i = N;
    list<int> Q;
    Q.push_back(N);
    levels[N] = 0;
    points[N].explored = true;
    
    while(!Q.empty()){
        i = Q.front();
        Q.pop_front();

        // printf("%d => %d,%d\t", i, points[i].x, points[i].y);
        // printf(" Index:%d Target%d\n", i, N+1);
        if(i == N+1)return levels[N+1];

        while(!connected[i].empty()){
            if(!points[connected[i].front()].explored){
                Q.push_back(connected[i].front());
                levels[connected[i].front()] = levels[i] + 1;
                // printf("::: Next index:%d LV: %d\n", connected[i].front(), levels[connected[i].front()]);
                points[connected[i].front()].explored = true;
            }
            connected[i].pop_front();
        }
    }
    return -1;
}

int main(){
    scanf("%d %d", &N, &R2);
    R2 = pow(R2, 2);
    for(int i=0;i<N;i++){
        scanf("\n%d %d", &points[i].x, &points[i].y);
        for(int j=0;j<i;j++){
            if (R2 >= (pow(points[j].x-points[i].x,2)+pow(points[j].y-points[i].y,2)))
            {
                connected[i].push_back(j);
                connected[j].push_back(i);
                // connected[i].sort();
                // connected[j].sort();
            }
            
        }
    }
    points[N].x = 0;
    points[N].y = 0;
    points[N+1].x = 100;
    points[N+1].y = 100;
    for(int j=0;j<N;j++){
        if (R2 >= (pow(points[j].x-points[N].x,2)+pow(points[j].y-points[N].y,2)))
        {
            connected[N].push_back(j);
            connected[j].push_back(N);
            // connected[N].sort();
            // connected[j].sort();
        }
        
    }
    for(int j=0;j<N+1;j++){
        if (R2 >= (pow(points[j].x-points[N+1].x,2)+pow(points[j].y-points[N+1].y,2)))
        {
            connected[N+1].push_back(j);
            connected[j].push_back(N+1);
            // connected[N+1].sort();
            // connected[j].sort();
        }
        
    }

    if(false){
        for(int i=0;i<N+2;i++){
            printf("%d %d:", points[i].x, points[i].y);
            while(!connected[i].empty()){
                printf(" (%d,%d)", points[connected[i].front()].x, points[connected[i].front()].y);
                connected[i].pop_front();
            }
            printf("\n");
        }
    } else {
        printf("%d\n", explore());
    }
    return 0;
}
