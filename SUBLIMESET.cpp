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
// wens
const int N=200005;
list<int> gr[N];
int ans[N];
int vis[N];
int sol(int cur)
{
 vis[cur]=1;
 int c=0;
 for(auto nbr:gr[cur])
 {
  if(!vis[nbr])
  {
    c++;
    ans[cur]+=sol(nbr);
  }
 }
 if(c==0)
 {
  return -1;
  cout<<cur;
 }
else
 return ans[cur];
}
void solve()
{
  w(t)
  {
    int c,p;
    cin>>c>>p;
    int h[c],r[c];
    f(i,0,c)
    cin>>h[c];
    f(i,0,c)
    cin>>r[c];
    for(int i=0;i<c-1;i++)
    {
      int x,y;
      cin>>x>>y;
      gr[x].pb(y);
      gr[y].pb(x);
    }
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
   sol(1);
   for(int i=1;i<=c;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  }
}
int32_t main()
{
    io();
    solve();
    return 0;
}