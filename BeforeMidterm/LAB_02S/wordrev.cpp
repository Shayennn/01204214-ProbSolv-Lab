#include <iostream>
using namespace std;

void reverse(char* str){
    if (str[1] != '\0')reverse(str+1);
    cout << str[0];
}

int main(){
    char S[1001], T[1001] = "";
    char t = 0;
    cin >> S;
    for(int i=0;S[i] != '\0';i++){
        if(S[i] != '_'){
            T[t++] = S[i];
        }
        if(S[i+1] == '_' || S[i+1] == '\0'){
            T[t] = '\0';
            reverse(T);
            if(S[i+1] == '_')cout << '_';
            t = 0;
        }
    }
}
