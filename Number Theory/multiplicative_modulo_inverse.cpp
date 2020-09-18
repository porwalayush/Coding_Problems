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
  int a,m;     /*     want to value of b if (a*b)%m==1     */
  cin>>a>>m;
  if(__gcd(a,m)==1)
  {
    extended(a,m);      /*   advantage of extended euclid algo  */
    cout<<(x+m)%m;   /* we can print x but extended function can give negative value sometimes */
  }
  else
    cout<<"not exist";
}
int32_t main()
{
    io();
    solve();
    return 0;
}