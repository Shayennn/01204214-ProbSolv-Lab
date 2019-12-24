// #include <iostream>
#include <stdio.h>
// #include <cstdlib>

// using namespace std;

typedef int valueType;

struct Train
{
  valueType trainID;
  Train* next;

  Train(valueType trainID, Train* next=0)
    : trainID(trainID), next(next) {}
};

void add_train(Train* tail, valueType trainID)
{
    tail->next->next = new Train(trainID);
    tail->next = tail->next->next;
}

void move_train(Train* src_header, Train* src_tail, Train* dst_tail)
{
    dst_tail->next->next = src_header->next;
    if(src_header->next != 0){
        dst_tail->next = src_tail->next;
    }
    src_header->next = 0;
    src_tail->next = src_header;
}

int main()
{
    Train* headers[100000];
    Train* tails[100000];
    for(int i = 0; i<100000; i++){
        headers[i] = new Train(0);
        tails[i] = new Train(0, headers[i]);
    }
    int M, X, Y;
    char cmd;
    scanf("%d", &M);
    // cin >> M;
    for(int i = 0; i<M; i++){
        scanf("\n%c %d %d", &cmd, &X, &Y);
        // cin >> cmd >> X >> Y;
        // cout << "[DB] [CMD] " << cmd << " " << X << " " << Y << endl;
        // printf("OK I know. CMD:%c %d %d\n", cmd, X, Y);
        if(cmd == 'N'){
            add_train(tails[Y-1], X);
        }else
        {
            move_train(headers[X-1], tails[X-1], tails[Y-1]);
        }
        
    }
    for(int i = 0; i<100000; i++){
        while (headers[i]->next != 0)
        {
            headers[i] = headers[i]->next;
            printf("%d\n", headers[i]->trainID);
            // cout << headers[i]->trainID << endl;
        }
    }
    return 0;
}
