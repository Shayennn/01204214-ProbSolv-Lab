#include <iostream>

using namespace std;

int main(){
    int n, truck=0, temp, buf=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        if(buf+temp > 1000){
            buf = temp;
            truck++;
        }else{
            buf+=temp;
        }
    }
    if(buf != 0) truck++;
    cout << truck << endl;
    return 0;
}
