#include <cstdio>

int n;
int m;
int lvl = 1;
int req[1002][3];
int pass[3];
int play[3];

bool isPass()
{
    for (int i = 0; i < 3; i++)
        if (pass[i] == 0) return false;
    return true;
}

void resetPass()
{
    for (int i = 0; i < 3; i++)
        pass[i] = 0;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int nn = 2; nn <= n; ++nn)
    {
        for (int i = 0; i < 3; ++i)
            scanf("%d", &req[nn][i]);
    }
    for (int mm = 0; mm < m; ++mm)
    {
        if (lvl == n) break;
        for (int i = 0; i < 3; ++i)
        {
            scanf("%d", &play[i]);
            if (req[1 + lvl][i] <= play[i]) pass[i] = 1;
        }
        if (isPass())
        {
            ++lvl;
            resetPass();
        }
    }
    if(lvl > n){
        printf("%d", n);
    }else{
        printf("%d", lvl);
    }
    return 0;
}