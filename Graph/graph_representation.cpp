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
	void print()
	{
		for(auto it:m)
		{
			cout<<"vertex"<<"->"<<it.first<<"->";
			list<T> l=it.second;
			for(auto iter:l)
				cout<<iter<<" ";
			cout<<endl;
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
    g.print();
	return 0;
}