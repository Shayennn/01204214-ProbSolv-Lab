#include <iostream>

using namespace std;

bool check_prime(int p)
{
  if (p <= 1) {
    return false;
  }
  int i = 2;
    while(i<p){

        if (p%(i++) == 0){
            return false;
        }
    }
    return true;
}

int main()
{
  int p;
  cin >> p;
  while(true){
    p++;
    if(check_prime(p)){
      cout << p << endl;
      break;
    }
  }
}
