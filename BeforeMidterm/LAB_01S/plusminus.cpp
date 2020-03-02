#include <iostream>
using namespace std;

int main(){
    int N, sum, tmp;
    char opr;
    cin >> N;
    cin >> sum;
    for(int i=1;i<N;i++){
        cin >> opr;
        cin >> tmp;
        if(opr=='+')sum+=tmp;
        else sum-=tmp;
    }
    cout << sum << endl;
}
