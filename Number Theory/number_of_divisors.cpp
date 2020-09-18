#include<bits/stdc++.h>
using namespace std;
#define ll long long
void io()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
const int m=100000;
int divisors[m];
void solve()
{
  for(int i=1;i<=m;i++)
    divisors[i]=0;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j*j<=i;j++)
    {
      if(i%j==0)
      {
        if(j!=(i/j))
          divisors[i]+=2;   //one divisor is j and other is i/j
        else
          divisors[i]+=1;
      }
    }
  }
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    cout<<divisors[n];
    cout<<endl;
  }
}
int32_t main()
{
    io();
    solve();
    return 0;
}