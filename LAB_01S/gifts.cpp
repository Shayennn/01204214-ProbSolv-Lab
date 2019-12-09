#include <iostream>
using namespace std;

int main(){
    int sum=0, temp, N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> temp;
        if(temp > 0)sum+=temp;
    }
    cout << sum << endl;
}