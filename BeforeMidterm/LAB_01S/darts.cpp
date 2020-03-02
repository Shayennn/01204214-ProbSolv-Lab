#include <iostream>
using namespace std;

int main(){
    int N, score=0, x, y, r2;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x;
        cin >> y;
        r2 = x*x+y*y;
        if(r2 <= 2*2)score+=5;
        else if(r2 <= 4*4)score+=4;
        else if(r2 <= 6*6)score+=3;
        else if(r2 <= 8*8)score+=2;
        else if(r2 <= 10*10)score+=1;
    }
    cout << score << endl;
}
