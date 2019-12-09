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

    // Init count
    cmd_count[0] = 0;
    cmd_count[1] = 0;
    cmd_count[2] = 0;
    cmd_count[3] = 0;

    // Count cmd
    for(int i=0; i<=100; i++){
        if(cmd[i] == '\0'){
            if(K>i)K=i;
            break;
        }
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

    // Choose cmd to reduce
    if(cmd_count[0] > cmd_count[1])first_reduce=1;
    if(cmd_count[2] > cmd_count[3])second_reduce=3;

    // Reduce cmd
    while(K!=0){

        // Reduce y axis
        if(cmd_count[first_reduce]>0){
            cmd_count[first_reduce]--;
            K--;
        }
        // Reduce x axis
        else if(cmd_count[second_reduce]>0){
            cmd_count[second_reduce]--;
            K--;
        }
        // Switch mode to reduce other command.
        else if(best_choice){
            first_reduce = (first_reduce == 1)?0:1;
            second_reduce = (second_reduce == 2)?3:2;
            best_choice = false;
        }
        // If no cmd to reduce exit loop
        if(cmd_count[0]+cmd_count[1]+cmd_count[2]+cmd_count[3] == 0)break;
    }
    cout << abs(cmd_count[0]-cmd_count[1]+cmd_count[2]-cmd_count[3])*2 << endl;
}
