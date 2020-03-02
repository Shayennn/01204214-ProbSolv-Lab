#include <stdio.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode* before;

  ListNode(int val, ListNode* next=0, ListNode* before=0)
    : val(val), next(next), before(before) {}
};

ListNode* First;
ListNode* Current;

void test(int N){
    for (int i = 0; i < N; i++)
    {
        if(Current->next == First->next){
            printf("(%d) -> ", First->next->val);
        }else{
            printf("%d -> ", First->next->val);
        }
        First->next = First->next->next;
    }
    printf("\n");
}

int main()
{
    ListNode* tmpNode;
    First = new ListNode(0);
    Current = new ListNode(0);
    Current->next = 0;
    int N, M, T, V, tmp;
    scanf("%d %d", &N, &M);
    scanf("%d", &tmp);
    Current->next = new ListNode(tmp);
    First->next = Current->next;
    Current->next->next = Current->next;
    Current->next->before = Current->next;
    for(int i = 1; i<N; i++){
        scanf(" %d", &tmp);
        tmpNode = new ListNode(tmp);
        tmpNode->before = Current->next;
        tmpNode->next = Current->next->next;
        tmpNode->next->before = tmpNode;
        Current->next->next = tmpNode;
        Current->next = tmpNode;
    }
    Current->next = First->next;
    for(int i = 0; i<M; i++){
        scanf("%d", &T);
        if(T>2)scanf(" %d", &V);
        switch (T)
        {
        case 1:
            Current->next = First->next;
            break;
        case 2:
            Current->next = Current->next->next;
            break;
        case 3:
            tmpNode = new ListNode(V, Current->next, Current->next->before);
            Current->next->before->next = tmpNode;
            Current->next->before = tmpNode;
            if(First->next == Current->next)First->next = tmpNode;
            N++;
            break;
        case 4:
            tmpNode = new ListNode(V, Current->next->next, Current->next);
            Current->next->next->before = tmpNode;
            Current->next->next = tmpNode;
            N++;
            break;
        }
        // test(N);
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", First->next->val);
        First->next = First->next->next;
    }
    

}