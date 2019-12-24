#include <iostream>
#include <cstdlib>

using namespace std;

typedef int valueType;

struct TrainStation
{
  valueType platform;
  valueType trainID;
  TrainStation* next;

  TrainStation(valueType platform, valueType trainID, TrainStation* next=0)
    : platform(platform), trainID(trainID), next(next) {}
};

void add_train(TrainStation* header, valueType platform, valueType trainID)
{
    TrainStation* p = header;
    TrainStation* newTrain = new TrainStation(platform, trainID);
    while (p->next != 0 && p->next->platform <= platform)
    {
        // cout << "[DB] BL1: T" << p->trainID << ":P" << p->platform << endl;
        p = p->next;
    }
    newTrain->next = p->next;
    p->next = newTrain;
}

void move_train(TrainStation* header, valueType platform_src, valueType platform_dst){
    /**
     * _header = ptr to header
     * so _header->next = that data
     **/
    if(platform_src==platform_dst)return;
    // cout << "[DB] " << platform_src << " to " << platform_dst << endl; 
    TrainStation* move_header = header;
    TrainStation* move_tail_header;
    TrainStation* tmp;
    TrainStation* tmp2;

    while(move_header->next != 0 && move_header->next->platform < platform_src){
        move_header = move_header->next;
        // cout << "[DB] MH: T" << move_header->trainID << ":P" << move_header->platform << endl;
    }

    if(move_header->next == 0 || move_header->next->platform != platform_src)return;
    move_tail_header = move_header;

    while(move_tail_header->next != 0 && move_tail_header->next->platform <= platform_src){
        move_tail_header = move_tail_header->next;
        if(move_tail_header == 0 || move_tail_header->platform != platform_src)return;
        move_tail_header->platform = platform_dst;
        // cout << "[DB] MT: T" << move_tail_header->trainID << ":P" << move_tail_header->platform << ":N" << move_tail_header->next << endl;
    }

    if(move_tail_header == move_header)return;
    
    // cout << "[DB] MH: T" << move_header->trainID << ":P" << move_header->platform << endl;
    // cout << "[DB] MT: T" << move_tail_header->trainID << ":P" << move_tail_header->platform << endl;
    // Code to swap pointer
    tmp = move_header->next;
    move_header->next = move_tail_header->next;
    move_tail_header->next = 0;
    while(tmp != 0){
        add_train(header, platform_dst, tmp->trainID);
        tmp2=tmp;
        // cout << "[DB] Reinsert TrainID: " << tmp->trainID << endl;
        tmp = tmp->next;
        delete tmp2;
    }
}

int main()
{
    TrainStation* header = new TrainStation(0, 0);
    header->next = 0;
    int M, X, Y;
    char cmd;
    cin >> M;
    for(int i = 0; i<M; i++){
        cin >> cmd >> X >> Y;
        if(cmd == 'N'){
            add_train(header, Y, X);
        }else
        {
            move_train(header, X, Y);
        }
    }
    while(header->next != 0){
        cout << header->next->trainID << endl;
        // cout << "[DB] T" << header->next->trainID << ":P" << header->next->platform << endl;
        header = header->next;
    }
}
