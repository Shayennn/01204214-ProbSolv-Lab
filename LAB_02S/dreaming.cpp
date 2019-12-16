#include <iostream>
using namespace std;

int char2digit(char a){
    if(a=='0')return 0;
    if(a=='1')return 1;
    if(a=='2')return 2;
    if(a=='3')return 3;
    if(a=='4')return 4;
    if(a=='5')return 5;
    if(a=='6')return 6;
    if(a=='7')return 7;
    if(a=='8')return 8;
    if(a=='9')return 9;
    else return 0;
}

char digit2char(int a){
    if(a==0)return '0';
    if(a==1)return '1';
    if(a==2)return '2';
    if(a==3)return '3';
    if(a==4)return '4';
    if(a==5)return '5';
    if(a==6)return '6';
    if(a==7)return '7';
    if(a==8)return '8';
    if(a==9)return '9';
    else return '0';
}

int main(){
    char A[303], B[303], C[304];
    int len_a = 0, len_b = 0, max_len, x=0;
    cin >> A;
    cin >> B;
    for(int i = 0; A[i] != '\0'; i++){
        len_a = i+1;
    }
    for(int i = 0; B[i] != '\0'; i++){
        len_b = i+1;
    }
    max_len = len_a;
    if(len_b > max_len) max_len = len_b;
    C[max_len+1] = '\0';
    for(int i = max_len; i >=0; i--){
        C[i] = digit2char(
            (x+char2digit(A[--len_a])+char2digit(B[--len_b])
            )%10
        );
        if((x+char2digit(A[len_a])+char2digit(B[len_b]))/10 == 1){
            x = 1;
        }else{
            x = 0;
        }
    }
    if (C[0] == '0'){
        for(int i = 1; C[i] != '\0'; i++){
            cout << C[i];
        }
    }else{
        for(int i = 0; C[i] != '\0'; i++){
            cout << C[i];
        }
    }
}
