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
list<int> gr[N],grr[N];
int visited[N];
vector<int> st;
int color[N];
void dfs(int cur)
{
  visited[cur]=1;
  for(auto nbr:gr[cur])
  {
    if(!visited[nbr])
      dfs(nbr);
  }
 st.pb(cur);
}
void dfs_reverse(int cur,int col)
{
  visited[cur]=1;
  for(auto nbr:grr[cur])
  {
    if(!visited[nbr])
      dfs_reverse(nbr,col);
  }
  color[cur]=col;
}
void solve()
{
 int v,e;
 cin>>v>>e;
 for(int i=0;i<e;i++)
 {
  int x,y;
  cin>>x>>y;
  gr[x].pb(y);
  grr[y].pb(x);
 }
 memset(visited,0,sizeof(visited));
for(int i=1;i<=v;i++)
{
  if(!visited[i])
    dfs(i);
}
memset(visited,0,sizeof(visited));
int col=0;
for(int i=v-1;i>=0;i--)
{
  if(!visited[st[i]])
  {
    dfs_reverse(st[i],col);
  col++;
}
}
for(int i=1;i<=v;i++)
{
  cout<<i<<"->"<<color[i]<<endl;
}
}
int32_t main()
{
    io();
    solve();
    return 0;
}