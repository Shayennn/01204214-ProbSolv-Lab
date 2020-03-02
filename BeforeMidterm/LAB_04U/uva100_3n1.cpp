#include <stdio.h>

/*
input n
print n

while(n != 1)
    if(n%2 == 1) n = 3n + 1;
    else n = n/2;
    print n
*/

int three_n_1(int n){

    int x=1;

    while(n != 1){
        ++x;
        if(n%2 == 1) n = 3*n + 1;
        else n = n/2;
    }

    return x;

}

int main(){
    int i, j, d = 0, e = 0 , b, c;

    while(true){
        b=0;
        if(scanf("%d %d", &i, &j) == EOF)break;
        d = i;
        e = j;
        if(i > j){
            i = e;
            j = d;
        }
        for(int a=i; a<=j; a++){
            c = three_n_1(a);
            if(c > b) b = c;
        }
        printf("%d %d %d\n", d, e, b);
    }

    return 0;
}
