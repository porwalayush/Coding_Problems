#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph
{
    map<T,list<T>> m;
  public:
	void addEdge(int x,int y)
	{
       m[x].push_back(y);
       m[y].push_back(x);
	}
	void bfs(int v,int start)
	{
		queue<T> q;
		map<T,int> visited;
    for(int i=1;i<=v;i++)
    {
      visited[i]=INT_MAX;
    }
		q.push(start);
    visited[start]=0;
		while(!q.empty())
		{
			T f=q.front();
			q.pop();
            list<T> l=m[f];
            for(auto it:l)
            {
            	if(visited[it]==INT_MAX)
            	{
            		q.push(it);
            		visited[it]=6+visited[f];
            	}
            }
		}
    for(auto it:visited)
    {
      if(it.second==INT_MAX)
        cout<<-1<<" ";

      else if(it.second!=0)
      cout<<it.second<<" ";
    }

	}
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin>>t;
  while(t--)
  {
    int n,e;
    cin>>n>>e;
    graph<int> g;
    while(e--)
    {
      int x,y;
      cin>>x>>y;
      g.addEdge(x,y);
    }
    int start;
    cin>>start;
    g.bfs(n,start);
    cout<<endl;
  }
	return 0;
}