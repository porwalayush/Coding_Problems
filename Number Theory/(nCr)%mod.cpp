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
int mod=1000000007;
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
   cin>>a>>b;
   int fact[a+1];
   fact[0]=1;
   for(int i=1;i<=a;i++)
    fact[i]=(fact[i-1]*i)%mod;
    int val1=modulo_exponential(fact[b],mod-2);
    int val2=modulo_exponential(fact[a-b],mod-2);
    int ans1=(fact[a]*val1)%mod;
    int ans=(ans1*val2)%mod;
    cout<<ans;
}
int32_t main()
{
    io();
    solve();
    return 0;
}