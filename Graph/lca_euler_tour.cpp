#include<bits/stdc++.h>
using namespace std;
const int N=10000,M=22;  //m=22 for 10^5 no of nodes 
vector<int> gr[N];
int parent[N][M];
int depth[N],tin[N],tout[N],timer;
void dfs(int cur,int par)
{
  tin[cur]=++timer;
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
  tout[cur]=timer;
  return;
}
bool is_ancestor(int x,int y)
{
  return tin[x]<=tin[y] && tout[x]>=tout[y];
}
int lca_euler_tour(int x,int y)
{
  if(is_ancestor(x,y))  return x;
  if(is_ancestor(y,x))  return y;


  for(int i=M-1;i>=0;i--)
  {
    if(!is_ancestor(parent[x][i],y))
    {
      x=parent[x][i];
    }
  }
  return parent[x][0];
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
  timer=0;
  tin[0]=0, tout[0]=n+1;
  dfs(1,0);
  // for(int i=1;i<=n;i++)
  // {
  //   cout<<i<<" "<<depth[i]<<" "<<parent[i]<<endl;
  // }
  cout<<lca_euler_tour(11,11);
  return 0;
}






// input
// 19
// 1 2
// 1 3
// 2 4
// 2 5
// 5 6
// 6 7
// 6 8
// 6 9
// 3 10
// 3 11
// 10 17
// 17 18
// 17 19
// 11 12
// 12 13
// 12 14
// 12 15
// 15 16