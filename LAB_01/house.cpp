#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int N, L;
    cin >> N;
    cin >> L;
    int house[10];
    int inrange = 0;
    for(int i = 0; i<N; i++){
        cin >> house[i];
        for(int j=0; j<i; j++){
            if(abs(house[i]-house[j]) <= L){
                inrange++;
            }
        }
    }
    cout << inrange << endl;
    return 0;
}
