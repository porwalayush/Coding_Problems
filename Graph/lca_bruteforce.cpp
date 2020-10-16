#include<bits/stdc++.h>
using namespace std;
const int N=10000;
vector<int> gr[N];
int depth[N],parent[N];
void dfs(int cur,int par)
{
  parent[cur]=par;
  for(auto x: gr[cur])
  {
    if(x!=par)
    {
      depth[x]=depth[cur]+1;
      dfs(x,cur);
    }
  }
  return;
}
int lca_brute(int x,int y)
{
  if(x==y) return x;
  if(depth[x]<depth[y])  swap(x,y);

  while(depth[x]>depth[y])
  {
    x=parent[x];
  }
  while(x!=y)
  {
    x=parent[x];
    y=parent[y];
  }
  return x;
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n,m;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int x,y;
    cin>>x>>y;
    gr[x].push_back(y);
    gr[y].push_back(x);
  }
  depth[1]=0;
  dfs(1,0);
  // for(int i=1;i<=n;i++)
  // {
  //   cout<<i<<" "<<depth[i]<<" "<<parent[i]<<endl;
  // }
  cout<<lca_brute(4,9);
  return 0;
}