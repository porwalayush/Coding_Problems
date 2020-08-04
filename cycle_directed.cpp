#include<bits/stdc++.h>
using namespace std;
const int N=200005;
list<int> gr[N];
int visited[N];
int path[N];
int c=0;
void dfs(int cur)
{
	visited[cur]=1;
	path[cur]=1;
	for(auto nbr:gr[cur])
	{
		if(!visited[nbr])
			dfs(nbr);
		else{
			if(path[nbr]==1)
			{
				for(int i=nbr;i<N;i++)
				{
					if(path[i]==1)
						cout<<i;
				}
				cout<<"cycle is present"<<endl;
				c++;
				return;
			}
		}
	}
	path[cur]=0;
	return;

}
int main()
{
	#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
	}
	memset(visited,0,sizeof(visited));
	memset(path,0,sizeof(path));
    dfs(1);
    if(c==0)
    	cout<<"NO cycle is present" <<endl;
	return 0;
}