#include<bits/stdc++.h>
using namespace std;
#define inf 10000
vector<vector<int>> floyd_warshal(vector<vector<int>> graph)
{
  vector<vector<int>> dist(graph);
  int V=graph.size();
  for(int k=0;k<V;k++)
  {
    for(int i=0;i<V;i++)
    {
      for(int j=0;j<V;j++)
      {
        if(dist[i][j]>dist[i][k]+dist[k][j])
          dist[i][j]=dist[i][k]+dist[k][j];
      }
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
  vector<vector<int>> graph = {{0,inf,-2,inf},{4,0,3,inf},{inf,inf,0,2},{inf,-1,inf,0}};
  vector<vector<int>> final=floyd_warshal(graph);
  int v=graph.size();
  for(int i=0;i<v;i++)
  {
    for(int j=0;j<v;j++)
    {
      cout<<final[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}