#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

void print_array(vector<int> & a) {
  for (int i = 0; i < a.size(); ++i) {
    printf("%d\n", a[i]);
  }
}

void reconstruct_print(int end, vector<int>&a, vector<int>&p) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x])
    s.push(a[x]);
  printf("%d\n", a[x]);
  for (; !s.empty(); s.pop())
    printf("%d\n", s.top());
  
}

int main(){
	int n;
	vector<int> numbers;
	vector<int> solution;
	while(scanf("%d", &n) == 1){
		numbers.push_back(n);
	}

	vector<int>L(numbers.size());
	vector<int>L_id(numbers.size());
	vector<int>P(numbers.size());
  int lis = 0, lis_end = 0;
  for (int i = 0; i < numbers.size(); ++i) {
    int pos = lower_bound(L.begin(), L.begin() + lis, numbers[i]) - L.begin();
    L[pos] = numbers[i];
    L_id[pos] = i;
    P[i] = pos ? L_id[pos - 1] : -1;
    if (pos + 1 > lis) {
      lis = pos + 1;
      lis_end = i;
    }
  }

  printf("%d\n-\n", lis);
  reconstruct_print(lis_end, numbers, P);
}