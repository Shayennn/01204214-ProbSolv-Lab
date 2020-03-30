#include "traffic.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, k;
int ans[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}}, ansI = 0;

bool isAns(int x1, int y1, int x2, int y2)
{
  for (int i = 0; i < ansI; i++)
  {
    if ((ans[i][0] == x1 && ans[i][1] == y1 && ans[i][2] == x2 && ans[i][3] == y2) || (ans[i][0] == x2 && ans[i][1] == y2 && ans[i][2] == x1 && ans[i][3] == y1))
      return true;
  }
  return false;
}
void addAns(int x1, int y1, int x2, int y2)
{
  if (ansI == 2 || isAns(x1, y1, x2, y2))
    return;
  ans[ansI][0] = x1;
  ans[ansI][1] = y1;
  ans[ansI][2] = x2;
  ans[ansI++][3] = y2;
}
void findCol(int y, int sx, int ex, int total)
{
  if (ansI == k)
    return;

  int lo = sx, hi = ex, mid, tmp;
  mid = floor(abs(hi + lo) / 2);
  if (total == -1)
    total = traffic_query(lo, y, hi, y);
  if (abs(lo - hi) == 1 && total == 2)
  {
    addAns(lo, y, hi, y);
  }
  else if (total <= abs(lo - hi))
  {
    return;
  }
  else
  {
    if ((tmp = traffic_query(lo, y, mid, y)) > abs(lo - mid))
      findCol(y, lo, mid, tmp);
    if (total - tmp > abs(mid - hi))
      findCol(y, mid, hi, total - tmp);
  }
  //}
}
void findRow(int x, int sy, int ey, int total)
{
  if (ansI == k)
    return;

  int lo = sy, hi = ey, mid, tmp;
  mid = floor(abs(hi + lo) / 2);
  if (total == -1)
    total = traffic_query(x, lo, x, hi);
  if (abs(lo - hi) == 1 && total == 2)
  {
    addAns(x, lo, x, hi);
  }
  else if (total <= abs(lo - hi))
  {
    return;
  }
  else
  {
    if ((tmp = traffic_query(x, lo, x, mid)) > abs(lo - mid))
      findRow(x, lo, mid, tmp);
    if (total - tmp > abs(mid - hi))
      findRow(x, mid, hi, total - tmp);
  }
}
int main()
{
  traffic_init(&n, &k);
  int tick = 0;
  for (int y = 1; y <= n; y++)
  {
    findCol(y, 1, n, -1);
  }
  for (int x = 1; x <= n; x++)
  {
    findRow(x, 1, n, -1);
  }

  traffic_report(
      ans[0][0], ans[0][1], ans[0][2], ans[0][3],
      ans[1][0], ans[1][1], ans[1][2], ans[1][3]);
}
