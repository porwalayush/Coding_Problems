#include<bits/stdc++.h>
using namespace std;
# define int long long
class graph
{
  int V;
  list<int> *l;
public:
  graph(int v)
  {
    V=v;
    l=new list<int>[V];
  }
  void addEdge(int x,int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);
  }
  void dfs_helper(int s,bool *visited)
  {
     visited[s]=true;
     for(auto nbr:l[s])
     {
      if(!visited[nbr])
      {
        cout<<nbr<<" ";
        dfs_helper(nbr,visited);
      }
     }
  }
  void dfs()
  {
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    {
      visited[i]=false;
    }
    cout<<0<<" ";
    dfs_helper(0,visited);
  }
};
int32_t main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    int v,e;
    cin>>v>>e;
    graph g(v);
    for(int i=0;i<e;i++)
    {
      int x,y;
      cin>>x>>y;
      g.addEdge(x,y);
    }
    g.dfs();
    cout<<endl;
  }
  return 0;
}