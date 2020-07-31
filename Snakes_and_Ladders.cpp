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
	}
	void bfs(int v,int start,int jump[])
	{
		queue<T> q;
		map<T,int> visited;
    for(int i=1;i<=v;i++)
    {
      visited[i]=INT_MAX;
    }
		q.push(start);
    visited[start]=0;
    int parent[101];
    parent[1]=0;
		while(!q.empty())
		{
			T f=q.front();
			q.pop();
            for(int i=1;i<=6;i++)
            {
              if(f+i<=v)
              {
            	if(visited[f+i+jump[f+i]]==INT_MAX)
            	{
            		visited[f+i+jump[f+i]]=visited[f]+1;
                q.push(f+i+jump[f+i]);

                parent[f+i+jump[f+i]] = f;
            	}
              }
            }
		}
    if(visited[100]==INT_MAX)
      cout<<-1;
    else
    cout<<visited[100];
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
    graph<int> g;
    int jump[101]={0};
    int l;
    cin>>l;
    while(l--)
    {
      int x,y;
      cin>>x>>y;
      g.addEdge(x,y);
      jump[x]=(y-x);
    }
    int s;
    cin>>s;
    while(s--)
    {
      int x,y;
      cin>>x>>y;
      g.addEdge(y,x);
      jump[x]=(y-x);
    }
    g.addEdge(100,100);
   g.bfs(100,1,jump);
   cout<<endl;
  }
	return 0;
}