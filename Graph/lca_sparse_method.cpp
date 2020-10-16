 #include<bits/stdc++.h>
using namespace std;
const int N=10000,M=22;  //m=22 for 10^5 no of nodes 
vector<int> gr[N];
int parent[N][M];
int depth[N];
void dfs(int cur,int par)
{
  parent[cur][0]=par;
  for(int i=1;i<M;i++)
    {
      parent[cur][i]=parent[parent[cur][i-1]][i-1];
    }
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
int lca_sparse_matrix(int u,int v)
{
  if(u==v) return u;
  if(depth[u]<depth[v]) swap(u,v);

  int diff=depth[u]-depth[v];
  for(int i=M-1;i>=0;i--)
  {
    if((diff>>i)&1)
    {
      u=parent[u][i];
    }
  }

  if(u==v)
    return u;

  for(int i=M-1;i>=0;i--)
  {
    if(parent[u][i]!=parent[v][i])
    {
      u=parent[u][i];
      v=parent[v][i];
    }
  }
  return parent[u][0];

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
  cout<<lca_sparse_matrix(18,16);
  return 0;
}