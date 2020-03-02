#include <stdio.h>

int char2int(char c){
    if(c == '1')return 1;
    else if(c == '2')return 2;
    else if(c == '3')return 3;
    else if(c == '4')return 4;
    else if(c == '5')return 5;
    else if(c == '6')return 6;
    else if(c == '7')return 7;
    else if(c == '8')return 8;
    else if(c == '9')return 9;
    else return 0;
}

int main(){

    char letter[9];
    int number;
    int a, c;

    scanf("%d", &c);

    for(int i = 0;i<c;i++){
        a = 0;
        number = 0;
        scanf("%8s", &letter);
        a+=(letter[0]-'A')*26*26;
        a+=(letter[1]-'A')*26;
        a+=(letter[2]-'A');
        number+=1000*(char2int(letter[4]));
        number+=100*(char2int(letter[5]));
        number+=10*(char2int(letter[6]));
        number+=(char2int(letter[7]));
        // printf(">>%d<<\n", number);
        // printf(">>%s<<\n", letter);
        // printf("%d %d %d\n", a, number, a-number);
        if((a-number)*(a-number)<=10000)printf("nice\n");
        else printf("not nice\n");
    }

    return 0;
}
