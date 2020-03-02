#include <iostream>
using namespace std;

int main(){
    int T;
    char in[101];
    cin >> T;
    char temp[101];
    int cur;
    for(int i=0;i < T; i++){
        cin >> in;
        cur = 0;
        for(int j=0; in[j] != '\0'; j++){
            if(in[j] == '{' || in[j] == '(' || in[j] == '[' || cur == 0){
                temp[cur++] = in[j];
            }else{
                if(temp[cur-1] == '{')
                {
                    if(in[j] == '}')cur--;
                    else {
                        // cout << "no" << endl;
                        break;
                    }
                }
                else if(temp[cur-1] == '[')
                {
                    if(in[j] == ']')cur--;
                    else {
                        // cout << "no" << endl;
                        break;
                    }
                }
                else if(temp[cur-1] == '(')
                {
                    if(in[j] == ')')cur--;
                    else {
                        // cout << "no" << endl;
                        break;
                    }
                }
            }
        }
        if(cur == 0)cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
