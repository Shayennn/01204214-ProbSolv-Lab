#include<stdio.h>

bool table[200001];

void init_table(){
    for (int i = 0; i < 200001; i++)
    {
        table[i] = true;
    }
    
}

int main(){
    init_table();
    table[0] = false;
    table[1] = false;

    int L, R, count = 0;

    scanf("%d %d", &L, &R);

    for (int i = 2; i < R+1; i++)
    {
        if(table[i]){
            if((i-2) >= L && i <= R && table[i-2]){
                count++;
            }
            for (int j = 2; i*j < 200001; j++)
            {
                table[i*j] = false;
            }
        }
    }
    printf("%d\n", count);

    return 0;
}
