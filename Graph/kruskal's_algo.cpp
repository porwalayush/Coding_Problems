#include<bits/stdc++.h>
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
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define f(i,s,n)        for(int i=s;i<n;i++)
int si= 2000005;
void io()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
const int N=200005;
int parent[N+1];
void init(int v)
{
  for(int i=1;i<=N;i++)
    parent[i]=i;
}
int get(int n)
{
  if(n==parent[n])
    return n;
  return parent[n]=get(parent[n]);
}
void unite(int x,int y)
{
  int parent1=get(x);
  int parent2=get(y);
  if(parent1!=parent2)
    parent[x]=y;
}
void solve()
{
    int v1,e;
    cin>>v1>>e;
    int sh[e];
    vector<vector<int>> v(e);
    init(v1);
    for(int i=0;i<e;i++)
    {
      int x,y,w;
      cin>>x>>y>>w;
      v[i]={w,x,y};
    }
    sort(v.begin(),v.end());
    int ans=0,pre=v[0][0];
    for(int i=0;i<e;i++)
    {
      int x=v[i][1];
      int y=v[i][2];
      int w=v[i][0];
      pre=0;
      if(get(x)!=get(y))
      {
        unite(x,y);
        ans=ans+w;
      }
    }
    cout<<ans<<endl;
}
int32_t main()
{
    io();
    solve();
    return 0;
}