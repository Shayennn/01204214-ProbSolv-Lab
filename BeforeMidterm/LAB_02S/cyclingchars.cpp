#include <iostream>
using namespace std;

int main(){
    char in[101];
    cin >> in;
    for(int i=0;in[i] != '\0'; i++){
        if (in[i]+4 > 'z'){
            cout << (char (in[i]+4-26));
        }else{
            cout << (char (in[i]+4));
        }
    }
}
