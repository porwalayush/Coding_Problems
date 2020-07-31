#include<bits/stdc++.h>
using namespace std;
# define int long long
class graph
{
  int V;
  list<pair<int,int>> *l;
public:
  graph(int v)
  {
    V=v;
    l=new list<pair<int,int>>[V];
  }
  void addEdge(int x,int y,int cost)
  {
  	l[x].push_back(make_pair(y,cost));
  	l[y].push_back(make_pair(x,cost));
  }
  int dfs_helper(int s,bool *visited,int *count,int &ans)
  {
     visited[s]=true;
     count[s]=1;
     for(auto nbr_pair:l[s])
     {
     	int nbr=nbr_pair.first;
     	int wt=nbr_pair.second;
     	if(!visited[nbr])
     	{
     		count[s]+=dfs_helper(nbr,visited,count,ans);
     		int nx=count[nbr];
     		int ny=V-nx;
     		ans+=(min(nx,ny)*2*wt);
     	}
     }
     return count[s];
  }
  int dfs(int s)
  {
  	bool *visited=new bool[V];
  	int *count=new int [V];
  	for(int i=0;i<V;i++)
  	{
  		visited[i]=false;
  		count[i]=0;
  	}
  	int ans=0;
  	dfs_helper(s,visited,count,ans);
    return ans;
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
	int w=1;
	while(t--)
	{
		int n;
		cin>>n;
		graph g(n);
		int c=n-1;
		while(c--)
		{
			int x,y,wt;
			cin>>x>>y>>wt;
			g.addEdge(x-1,y-1,wt);
		}
		cout<<"Case #"<<w<<": "<<g.dfs(0)<<endl;
		w++;
    }
	return 0;
}