//undirected
#include<bits/stdc++.h>
using namespace std;
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
  int bfs(int s)
  {
    int ans=V+1;
    queue<int> q;
    int dist[V];
    for(int i=0;i<V;i++)
    {
       dist[i]=INT_MAX;
    }
    q.push(s);
    dist[s]=0;
    while(!q.empty())
    {
      int node=q.front();
      q.pop();
       for(auto nbr:l[node])
       {
          if(dist[nbr]==INT_MAX)
          {
            dist[nbr]=dist[node]+1;
            q.push(nbr);
          }
          else if(dist[nbr]>=dist[node] )
          {
            ans=min(ans,(dist[nbr]+dist[node]+1));
          }

       }
       
    }
    return ans;
  }
  void solve()
  {
    int ans=V+1;
    for(int i=0;i<V;i++)
    {
       ans=min(ans,bfs(i));
    }
    cout<<ans;
  }
};
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int v,e;
  cin>>v>>e;
    graph g(v);
    for(int i=0;i<e;i++)
    {
      int x,y;
      cin>>x>>y;
      g.addEdge(x,y);
    }
    g.solve();
  return 0;
}