// find no of divisors %1000000007 of (a1*a2*a3*......*an)  where a[i]<1000000
#include<bits/stdc++.h>
using namespace std;
#define int long long
void io()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
const int MAXN=1000000;
int spf[MAXN];
map<int,int> m;
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    {  
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
void getFactorization(int x) 
{  
    while (x != 1) 
    { 
        m[spf[x]]++;
        x = x / spf[x]; 
    } 
} 
void solve()
{
    sieve();
  int t;
  cin>>t;
  while(t--)
  {
    m.clear();
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        getFactorization(a[i]);
    }
    int ans=1;
    for(auto it:m)
    {
        ans=(ans*(it.second+1))%1000000007;
    }
    cout<<ans<<endl;
  }
}
int32_t main()
{
    io();
    solve();
    return 0;
}