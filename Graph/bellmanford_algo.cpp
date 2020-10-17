#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> gr;
vector<int> bellmanford(int src,int V)
{
  vector<int> dist(V+1,INT_MAX);
  dist[src]=0;
  for(int i=0;i<V-1;i++)
  {
    for(auto edge:gr)
    {
      int u=edge[0];
      int v=edge[1];
      int wt=edge[2];
      if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt)
      {
        dist[v]=dist[u]+wt;
      }
    }
  }
  for(auto edge:gr)
    {
      int u=edge[0];
      int v=edge[1];
      int wt=edge[2];
      if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt)
      {
        dist[v]=dist[u]+wt;
        cout<<"negative weight cycle";
        exit(0);
      }
    }
    return dist;
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
    int x,y,wt;
    cin>>x>>y>>wt;
    gr.push_back({x,y,wt});
  }
  vector<int> ans=bellmanford(1,n);
  for(int i=1;i<=n;i++)
  {
    cout<<ans[i]<<" ";
  }
  return 0;
}




// 3 3
// 1 2 3
// 2 3 4
// 1 3 -10


// 3 3
// 1 2 3
// 2 3 4
// 3 1 -10