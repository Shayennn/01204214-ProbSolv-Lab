#include <cstdio>
#include <list>

using namespace std;

int main(){
    list<int> station;
    list<int> goal;
    int ipt, train;

    while(true){
        scanf("%d", &ipt);
        if(ipt == 0)break;

        while (true){
            goal.clear();
            station.clear();
            scanf("%d", &train);
            if(train == 0)break;
            goal.push_back(train);

            for(int i=1;i<ipt;i++){
                scanf(" %d", &train);
                goal.push_back(train);
            }

            for(int i=1;i<=ipt;i++){
                station.push_back(i);
                while(!station.empty() && station.back() == goal.front()){
                    goal.pop_front();
                    station.pop_back();
                }
            }

            if(station.empty())printf("Yes\n");
            else printf("No\n");

        }
        
        printf("\n");
    }

    return 0;
}