
#include <iostream>
using namespace std;

void copy_string(char* src, char* dest)
{
int pt1 = 0;
int pt2 = 0;
while(src[pt1] != '\0'){
    switch (src[pt1])
    {
    case '<':
        dest[pt2++] = '&';
        dest[pt2++] = 'l';
        dest[pt2++] = 't';
        dest[pt2++] = ';';
        break;
    
    case '>':
        dest[pt2++] = '&';
        dest[pt2++] = 'g';
        dest[pt2++] = 't';
        dest[pt2++] = ';';
        break;
    
    case '"':
        dest[pt2++] = '&';
        dest[pt2++] = 'q';
        dest[pt2++] = 'u';
        dest[pt2++] = 'o';
        dest[pt2++] = 't';
        dest[pt2++] = ';';
        break;
    
    default:
        dest[pt2++] = src[pt1];
        break;
    }
    pt1++;
}
dest[pt2] = '\0';

}

int main()
{
  char st1[1000];
  char st2[1000];

  cin.getline(st1,1000);
  copy_string(st1,st2);

  cout << st2 << endl;
}