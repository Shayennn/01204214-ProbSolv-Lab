#include <iostream>
#include <cstdlib>

using namespace std;

int genFaceCmd(int curFace, int d){
    int rotate = d-curFace;
    if (rotate<0) rotate+=4;
    for(int i=0; i<abs(rotate); i++){
        cout << 'R';
    }
    return rotate;
}


int main(){
    char cmd[101];
    int face=0, d=0;  //Face 0=N, 1=E, 2=S, 3=W
    cin >> cmd;
    for(int i=0; cmd[i]!='\0'&&i<100; i++){
        switch (cmd[i])
        {
        case 'N':
            d+=genFaceCmd(face, 0);
            face = 0;
            cout << 'F';
            d++;
            break;
        case 'S':
            d+=genFaceCmd(face, 2);
            face = 2;
            cout << 'F';
            d++;
            break;
        case 'E':
            d+=genFaceCmd(face, 1);
            face = 1;
            cout << 'F';
            d++;
            break;
        case 'W':
            d+=genFaceCmd(face, 3);
            face = 3;
            cout << 'F';
            d++;
            break;
        case 'Z':
            cout << 'Z';
            face = 0;
            d++;
            break;
        }
    }
    cout << endl;
}
