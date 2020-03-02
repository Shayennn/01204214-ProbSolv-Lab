#include <iostream>
using namespace std;

void reverse(char* str){
    if (str[1] != '\0')reverse(str+1);
    cout << str[0];
}

int main(){
    char S[1001];
    cin >> S;
    reverse(S);
}
