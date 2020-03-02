#include <iostream>
using namespace std;

int main()
{
  int a;
  cin >> a;
  for(int i=1; i<=a; i++){
      for(int j=i; j<=a; j++){
          cout << j;
      }
      for(int j=1; j<i; j++){
          cout << j;
      }
      cout << endl;
  }
}