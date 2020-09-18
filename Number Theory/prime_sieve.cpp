#include<bits/stdc++.h>
using namespace std;
#define int long long
void io()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int m=100000;
void solve()
{
  int ans[m+1];
  for(int i=0;i<=m;i++)
    ans[i]=0;
  ans[2]=1;
  for(int i=3;i<=m;i+=2)
    ans[i]=1;
  for(int i=2;i<=m;i++)
  {
    for(int j=i*i;j<=m;j=j+i)
    {
      ans[j]=0;
    }
  }
}
int32_t main()
{
    io();
    solve();
    return 0;
}