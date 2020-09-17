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
int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}
void solve()
{
  int a,b;
  cin>>a>>b;
  cout<<gcd(a,b);
}
int32_t main()
{
    io();
    solve();
    return 0;
}