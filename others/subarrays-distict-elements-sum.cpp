#include<bits/stdc++.h>
using namespace std;
# define mod 1000000007;
# define int long long
int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif


  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  int i=0,j=0;
  int ans=0;
  set<int> s;
    for(int i=0;i<n;i++)
    {
        while(j<n && s.find(a[j])==s.end())
    {
        s.insert(a[j]);
        j++;
    }
    int tmp=j-i;
    ans=ans+((tmp*(tmp+1)/2));
    ans=ans%mod;
    s.erase(a[i]);
    }
    cout<<ans;
  return 0;
}