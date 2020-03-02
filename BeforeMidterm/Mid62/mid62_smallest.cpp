#include <stdio.h>
#include <list>

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

int o_count = 0;

list<Cond>::iterator conds_helper[10000000];

list<Cond> conds;

int main(){
    int N, Q, T, k;
    Cond FUCK;
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++)
    {
        scanf("%d\n", &students[i]);
        if(FUCK_min > students[i]){
            FUCK_min = students[i];
            FUCK.index = i;
            FUCK.value = FUCK_min;
            conds.push_back(FUCK);
        }
        if(FUCK_max < students[i]) FUCK_max = students[i];
        mins[i]=FUCK_min;
    }
    list<Cond>::iterator it;
    for(int i=FUCK_min; i<=FUCK_min+100; i+=100){
        for (it = conds.begin(); it != conds.end(); ++it)
        {
            conds_helper[i/100] = it;
            if(i > it->value){
                break;
            }
        }
    }
    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &T, &k);
        if(T == 1){
            printf("%d\n", mins[k-1]);
        }else{
            if(k > students[0])printf("0\n");
            else if(k <= FUCK_min)printf("%d\n", N);
            else{
                for (it = conds_helper[k/100]; it != conds.end(); ++it)
                // for (it = conds.begin(); it != conds.end(); ++it)
                {
                    o_count++;
                    if(k > it->value){
                        printf("%d\n", it->index);
                        break;
                    }
                }
                
            }
        }
        // printf("\n\nO: %d\n", o_count);
    }
    
    
    return 0;
}