#include<bits/stdc++.h>
using namespace std;
const int N=10000;
vector<int> gr[N];
int low[N],disc[N],t;
set<int> arti_p;
vector<pair<int,int>> bridge;
void dfs(int cur,int par)
{
  low[cur]=disc[cur]=t++;
  int no_of_child=0;
  for(auto x: gr[cur])
  {
    if(disc[x]==0)
    {
      dfs(x,cur);
      no_of_child++;
      low[cur]=min(low[cur],low[x]);
      if(par!=0 && low[x]>= disc[cur])
      {
          arti_p.insert(cur);
      }
      if(low[x]> disc[cur])
      {
          bridge.push_back({x,cur});
      }
    }
    else if(x!=par)
    {
      // backedge
      low[cur]=min(low[cur],disc[x]);
    }
  }
  if(par==0 && no_of_child>1)
  {
      arti_p.insert(cur);
  }
  return;
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    gr[x].push_back(y);
    gr[y].push_back(x);
  }
  for(int i=0;i<N;i++)
    disc[i]=0;
  t=1;
  dfs(1,0);
  for(auto x:arti_p)
  {
    cout<<x<<" ";
  }
  return 0;
}