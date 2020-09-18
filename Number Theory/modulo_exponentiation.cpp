#include<bits/stdc++.h>
using namespace std;
int mod=1000000007;
void io()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int modulo_exponential(int a,int b)
{
  int r=1;
  while(b)
  {
    if(b&1) r=(r*a)%mod;
    a=(a*a)%mod;
    b=b>>1;
  }
  return r;
}
void solve()
{
  int a,b;
  cin>>a>>b;    /* we want (a^b)%mod   */
  cout<<modulo_exponential(a,b);
}
int32_t main()
{
    io();
    solve();
    return 0;
}