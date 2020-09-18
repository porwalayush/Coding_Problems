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
  /* find a number x  :->   (x%num[i])==rem[i]     x%2==1 && x%7==5 && x%3==2 then x=5  */
  int n;
  cin>>n;
  int num[n],rem[n];
  for(int i=0;i<n;i++)
  {
    cin>>num[i]>>rem[i];
  }
  int prod=1,pp[n],inv[n];
  for(int i=0;i<n;i++)
  {
    prod=prod*num[i];
  }
  for(int i=0;i<n;i++)
  {
    pp[i]=prod/num[i];
  }
  for(int i=0;i<n;i++)   /*modulo multiplicative inverse of pp[i] wrt num[i]  */
  {
    extended(pp[i],num[i]);
     inv[i]=(x+num[i])%num[i];
  }
  int ans=0;
  for(int i=0;i<n;i++)
  {
    ans=ans+((rem[i]*pp[i]*inv[i])%prod);
  }
  cout<<ans;
}
int32_t main()
{
    io();
    solve();
    return 0;
}