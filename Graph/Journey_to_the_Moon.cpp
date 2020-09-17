#include<bits/stdc++.h>
using namespace std;
# define int long long
int nCr(int n) 
{ 
    return (n*(n-1))/2;
} 
  
// Returns factorial of n 
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
	void dfs_helper(int s,map<T,bool> &visited,int &c)
	{
		while(!visited[s])
		{
			visited[s]=true;
      
			for(auto nb:m[s])
			{
				if(!visited[nb])
				{
          c++;
          dfs_helper(nb,visited,c);

				}
			}
		}

	}
	void dfs(int v)
	{ 
    int ans=0,c=0;
    ans=ans+nCr(v);
		map<T,bool> visited;
    for(int i=0;i<v;i++)
    {
      visited[i]=false;
    }
		int cnt=0;
       for(auto it:visited)
       {
        if(!it.second)
        {
          c=0;
          dfs_helper(it.first,visited,c);
          if(c>0)
           {
            ans=ans-nCr(c+1);
           }
          cnt++;

        }
       }
       cout<<ans<<endl;
	} 
};
int32_t main()
{
	#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
      int v,e;
      cin>>v>>e;
      graph<int> g;
      while(e--)
      {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
      }
      g.dfs(v);
    	return 0;
}