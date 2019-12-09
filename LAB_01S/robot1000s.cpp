#include <iostream>
#include <cstdlib>
using namespace std;


int main(){
    char cmd[101];
    int K, cmd_count[4];  // NSEW
    int first_reduce=0, second_reduce=2;
    bool best_choice = true;
    cin >> cmd;
    cin >> K;
    if(K>100)K=100;
    cmd_count[0] = 0;
    cmd_count[1] = 0;
    cmd_count[2] = 0;
    cmd_count[3] = 0;
    for(int i=0; i<100; i++){
        if(cmd[i] == '\0')break;
        switch (cmd[i])
        {
        case 'N':
            cmd_count[0]++;
            break;
        case 'S':
            cmd_count[1]++;
            break;
        case 'E':
            cmd_count[2]++;
            break;
        case 'W':
            cmd_count[3]++;
            break;
        }
    }
    if(cmd_count[0] > cmd_count[1])first_reduce=1;
    if(cmd_count[2] > cmd_count[3])second_reduce=3;
    for(int i=0;i<K;i++){
        if(cmd_count[first_reduce]>0)cmd_count[first_reduce]--;
        else if(cmd_count[second_reduce]>0)cmd_count[second_reduce]--;
        else if(best_choice){
            first_reduce = (first_reduce == 1)?0:1;
            second_reduce = (second_reduce == 2)?3:2;
            best_choice = false;
            i--;
        }
    }
    cout << abs(cmd_count[0]-cmd_count[1]+cmd_count[2]-cmd_count[3])*2 << endl;
}
