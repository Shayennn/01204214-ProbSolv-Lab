#include <iostream>

using namespace std;

typedef int valueType;

struct ICNode
{
  valueType number;
  ICNode* next;

  ICNode(valueType number, ICNode* next=0)
    : number(number), next(next) {}
};

void insert_left(ICNode* header, valueType number)
{
    if(header->next == 0)
    {
        header->next = new ICNode(number);
        header->next->next = header->next;
    }
    else
    {
        header->next->next = new ICNode(number, header->next->next);
    }
}

void insert_right(ICNode*& header, valueType number)
{
    insert_left(header, number);
    header->next = header->next->next;
}

void rotate_left(ICNode* header)
{
    header->next = header->next->next;
}

void rotate_right(ICNode*& header)
{
    ICNode* p = header->next;
    while(header->next->next != p)rotate_left(header);
}

int main()
{
    ICNode* header = new ICNode(0);
    ICNode* p;
    int M, X;
    char cmd[3];
    cin >> M;
    for(int i = 0; i<M; i++){
        cin >> cmd;
        if(cmd[1] == 'i'){
            cin >> X;
            if(cmd[0] == 'r')insert_right(header, X);
            if(cmd[0] == 'l')insert_left(header, X);
        }else if(cmd[1] == 'r' && header->next != 0)
        {
            if(cmd[0] == 'r')rotate_right(header);
            if(cmd[0] == 'l')rotate_left(header);
        }
    }
    if(header->next != 0){
        p = header->next;
        do{
            rotate_left(header);
            cout << header->next->number << endl;
        }while(header->next != p);
    }
}
