#include <iostream>

using namespace std;

struct BeadNode
{
  int number;
  BeadNode* next;

  BeadNode(int number, BeadNode* next=0)
    : number(number), next(next) {}
};


int main()
{
    BeadNode* headers[300000];
    bool necklaces[300000];
    BeadNode* p;
    int N, X, Y;
    cin >> N;
    for(int i=1; i<=N; i++){
        necklaces[i] = true;
        headers[i] = new BeadNode(0);
        headers[i]->next = new BeadNode(i);
        // headers[i-1]->next->next = headers[i]->next;
    }
    for(int i = 0; i<(N-1); i++){
        cin >> X >> Y;
        necklaces[X] = false;
        p = headers[X];
        do{
            p = p->next;
        }while(p->next != 0);
        p->next = headers[Y]->next->next;
        headers[Y]->next->next = headers[X]->next;
    }
    for(int i=1; i<=N; i++){
        if(necklaces[i]){
            while (headers[i]->next != 0)
            {
                headers[i] = headers[i]->next;
                cout << headers[i]->number << ' ';
            }
            break;
        }
    }
}