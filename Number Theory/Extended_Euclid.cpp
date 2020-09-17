#include<bits/stdc++.h>
using namespace std;
void io()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int x,y;
void extended(int a,int b)
{
  if(b==0)
  {
    x=1;
    y=0;
    return;
  }
  extended(b,a%b);
  int cx,cy;
  cx=y;
  cy=x-((a/b)*y);
  x=cx;
  y=cy;
  return;
}
void solve()
{
  int a,b;     /*     want to get value of x and y in      ax+by=gcd(a,b)   */
  cin>>a>>b;
  extended(a,b);
  cout<<x<<" "<<y;
}
int32_t main()
{
    io();
    solve();
    return 0;
}