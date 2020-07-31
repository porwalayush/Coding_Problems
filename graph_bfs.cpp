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
		bool visited[v];
		for(int i=0;i<v;i++)
			visited[i]=false;
		q.push(start);
		visited[start]=true;
		while(!q.empty())
		{
			T f=q.front();
			q.pop();
			cout<<f<<" ";
            list<T> l=m[f];
            for(auto it:l)
            {
            	if(!visited[it])
            	{
            		q.push(it);
            		visited[it]=true;
            	}
            }
		}

	}
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    graph<int> g;
    g.addEdge(0,1);
    g.addEdge(3,1);
    g.addEdge(0,2);
    g.addEdge(3,2);
    g.addEdge(0,4);
    g.bfs(5,0);
	return 0;
}