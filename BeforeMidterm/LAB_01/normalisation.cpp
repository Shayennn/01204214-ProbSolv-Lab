#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int a, int b){
    if (a<b) {
        int c;
        c=a;
        a=b;
        b=c;
    }
    if(a % b == 0){
        return b;
    }
    return gcd(b, a%b);
}

int main(){
    int a,b;
    cin >> a;
    cin >> b;
    if (b<0){
        a*=-1;
        b*=-1;
    }
    int this_gcd = gcd(a,b);
    a/=this_gcd;
    b/=this_gcd;
    cout << a << '/' << b << endl;
    return 0;
}

