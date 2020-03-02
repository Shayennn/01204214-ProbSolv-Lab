#include <iostream>
using namespace std;

int main(){
    char in[101];
    cin >> in;
    const int lower2upper = 'A'-'a';
    for(int i=0;in[i] != '\0'; i++){
        if (in[i] <= 'z' && in[i] >= 'a'){
            cout << (char (in[i]+lower2upper));
        }else{
            cout << (char (in[i]));
        }
    }
}
