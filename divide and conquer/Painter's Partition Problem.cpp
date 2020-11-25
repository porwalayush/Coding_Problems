#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define endl ("\n")
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
// #define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define f(i,s,n)        for(int i=s;i<n;i++)
void io()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
bool is_possible(int mid,int p,int b,int a[])
{
  int cnt=0, l=1;
  for(int i=0;i<b;i++)
  {
    if(a[i]>mid)
      return false;
    cnt+=a[i];
    if(cnt>mid)
    {
      cnt=0;
      cnt+=a[i];
      l++;
    }
  }
  if(l<=p)
    return true;
  return false;
}
void solve()
{
  int p,b;
  cin>>p>>b;
  int a[b];
  int sum=0,mx=0;
  f(i,0,b)
  {
    cin>>a[i];
    sum+=a[i];
    mx=max(mx,a[i]);
  }
  int s=mx;
  int e=sum;
  int m;
  int ans;
  while(s<=e)
  {
    m=(s+e)/2;
    if(is_possible(m,p,b,a))
    {
      e=m-1;
      ans=m;
    }
    else
      s=m+1;
  } 
  cout<<ans;
}
int32_t main()
{
    io();
    solve();
    return 0;
}