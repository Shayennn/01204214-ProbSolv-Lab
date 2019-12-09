#include <iostream>
using namespace std;

int main(){
    int x=0,y=0;
    char cmd[101];
    cin >> cmd;
    for(int i=0; cmd[i]!='\0'; i++){
        switch (cmd[i])
        {
        case 'N':
            y+=1;
            break;
        case 'S':
            y-=1;
            break;
        case 'E':
            x+=1;
            break;
        case 'W':
            x-=1;
            break;
        case 'Z':
            x=0;
            y=0;
            break;
        }
    }
    cout << x << ' ' << y << endl;
}