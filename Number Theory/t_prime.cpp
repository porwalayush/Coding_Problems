// a number is t-prime if it has only three divisors
#include<bits/stdc++.h>
using namespace std;
#define int long long
void io()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}
bool isPerfectSquare(long double x) 
{   
  long double sr = sqrt(x); 
  
  return ((sr - floor(sr)) == 0); 
} 
int m=1000000;
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
  int t;
  cin>>t;
  while(t--)
  {
  int n;
  cin>>n;
  if(isPerfectSquare(n))
  {
    int k=sqrt(n);
     if(ans[k]==1)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  else
  {
    cout<<"NO"<<endl;
  }
  }
}
int32_t main()
{
    io();
    solve();
    return 0;
}