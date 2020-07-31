#include<bits/stdc++.h>
using namespace std;
# define int long long
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
	void dfs_helper(int s,map<T,bool> &visited)
	{
		while(!visited[s])
		{
			visited[s]=true;
			for(auto nb:m[s])
			{
				if(!visited[nb])
				{
                   dfs_helper(nb,visited);
				}
			}
		}
	}
	void dfs(int c1,int c2,int &ans,int city)
	{
		map<T,bool> visited;
		for(auto it: m)
		{
			visited[it.first]=false;
		}int cnt=0,v=0;
       for(auto it:visited)
       {
       	v++;
       	if(!it.second)
       	{
       		dfs_helper(it.first,visited);
       		cnt++;

       	}
       	else
       		ans=ans+(c2*1);
       }
       if(c2>c1)
       	cout<<(v*c1)+((city-v)*c1)<<endl;
       else
       cout<<ans+(c1*cnt)<<endl;
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
      	int city,road,cost_lib,cost_road;
      	cin>>city>>road>>cost_lib>>cost_road;
      	graph<int> g;
      	set<int> s;
      	if(road==0)
         {
           
           	cout<<(city*cost_lib)<<endl;
         }
         else
         {
      	while(road--)
      	{
          int x,y;
          cin>>x>>y;
          s.insert(x);
          s.insert(y);
          g.addEdge(x,y);
      	}
      	int ans=0,p=1;
      	for(auto it:s)
      	{
           if(it-p!=0)
           {
           
           	ans=ans+(cost_lib*(it-p));
           }
           p=it+1;
      	}
      	if(p<=city)
      		ans=ans+(cost_lib*(city-(p-1)));
      	 g.dfs(cost_lib,cost_road,ans,city);
      	}
      }
	return 0;
}