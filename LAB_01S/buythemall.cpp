#include <iostream>
using namespace std;

int main(){
    int A,B,C,a=0,b=0,c=0,N,tmp;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        switch (tmp)
        {
        case 1:
            a+=1;
            break;
        case 2:
            b+=1;
            break;
        case 3:
            c+=1;
            break;
        }
    }
    tmp = A*a;
    N = a;
    if(B*b < tmp){
        tmp = B*b;
        N = B;
    }
    if(C*c < tmp){
        tmp = C*c;
        N = C;
    }
    cout << tmp << endl;
}
