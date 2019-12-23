#include <iostream>
#include <cstdlib>

using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

void insert_front(ListNode* header, valueType x)
{
    ListNode* old_second = header->next;
    header->next = new ListNode(x);
    header->next->next = old_second;
}

void free_list(ListNode*& header)
{
    ListNode* tmp = header->next;
    ListNode* tmp2;
    while(tmp->next != 0){
        tmp2 = tmp;
        tmp = tmp->next;
        delete tmp2;
    }
}

void delete_list(ListNode*& header, int index){
    index--;
    ListNode* p = header;
    ListNode* q;
    if(p == 0) return;
    for(int i=0; i<index;i++){
        if(p->next != 0)p = p->next;
        else return;
    }
    // if(p->next == 0)return;
    if(p->next == 0){
        q = 0;
    }else{
        q = p->next->next;
    }
    delete p->next;
    p->next = q;
}

int main()
{
    ListNode* header = new ListNode(0);
    int M, X;
    char cmd;
    cin >> M;
    for(int i = 0; i<M; i++){
        cin >> cmd >> X;
        if(cmd == 'I'){
            insert_front(header, X);
        }else
        {
            delete_list(header, X);
        }
        
    }
    while(header->next != 0){
        cout << header->next->val << endl;
        header = header->next;
    }
}