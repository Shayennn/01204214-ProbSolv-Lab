#include <iostream>
using namespace std;
int main()
{
  char c[100];
  int e = 0;
  cin >> c;
  while(c[e] != '\0'){
      e++;
  }
  bool err = false;
  for(int i = 0; i<e; i++){
      if(c[i] != c[e-i-1]){
          err = true;
      }
  }
  cout << (err?"no":"yes") << endl;
}