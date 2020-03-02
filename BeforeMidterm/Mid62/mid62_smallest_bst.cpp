#include <stdio.h>
#include <list>
#include <math.h>

using namespace std;

struct Cond
{
  int value;
  int index;
};

int students[200001];
int mins[200001];
int FUCK_min = 1000000000;
int FUCK_max = 0;

int conds[200001][2];
int conds_count = 0;
bool searchtraveled[200001];

void reset_history(){
    for (int i = 0; i < conds_count; i++)
    {
        searchtraveled[i] = false;
    }
}

int bstsearch(int what, int start, int stop){
    int center = (int) roundf(((float)stop - (float)start)/2);
    // printf("What: %d\tStart: %d\tStop: %d\tCenter: %d\n", what, start, stop, center);
    if(searchtraveled[center])return center;
    searchtraveled[center] = true;
    if(what > conds[center][1]){
        return bstsearch(what, start, center);
    }else if(what < conds[center][1]){
        return bstsearch(what, center, stop);
    }else{
        return center+1;
    }
}

// list<Cond> old_conds;

int main(){
    int N, Q, T, k;
    Cond FUCK;
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++)
    {
        scanf("%d\n", &students[i]);
        if(FUCK_min > students[i]){
            FUCK_min = students[i];
            conds[conds_count][0]=i;
            conds[conds_count++][1]=FUCK_min;
            // FUCK.index = i;
            // FUCK.value = FUCK_min;
            // old_conds.push_back(FUCK);
        }
        if(FUCK_max < students[i]) FUCK_max = students[i];
        mins[i]=FUCK_min;
    }
    // list<Cond>::iterator it;
    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &T, &k);
        if(T == 1){
            printf("%d\n", mins[k-1]);
        }else{
            if(k > students[0])printf("0\n");
            else if(k <= FUCK_min)printf("%d\n", N);
            else{
                reset_history();
                printf("%d\n", conds[bstsearch(k, 0, conds_count)][0]);
                // for (it = old_conds.begin(); it != old_conds.end(); ++it)
                // {
                //     if(k > it->value){
                //         printf("%d\n", it->index);
                //         break;
                //     }
                // }
            }
        }
    }
    
    
    return 0;
}