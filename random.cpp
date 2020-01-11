#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand (time(NULL));
    if(rand()%10 < 7)printf("yes");
    else printf("no");
}
