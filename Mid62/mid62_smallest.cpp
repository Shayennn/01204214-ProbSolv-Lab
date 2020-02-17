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
    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &T, &k);
        if(T == 1){
            printf("%d\n", mins[k-1]);
        }else{
            if(k > students[0])printf("0\n");
            else if(k <= FUCK_min)printf("%d\n", N);
            else{
                for (it = conds.begin(); it != conds.end(); ++it)
                {
                    if(k > it->value){
                        printf("%d\n", it->index);
                        break;
                    }
                }
                
            }
        }
    }
    
    
    return 0;
}