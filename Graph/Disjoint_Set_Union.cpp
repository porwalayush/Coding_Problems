// c is the count of cycle in graph in undierected graph
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int c=0;
int parent[N+1];
void make(int v)
{
  for(int i=1;i<=v;i++)
  	parent[i]=i;          //intialization
}
int get(int n)
{
	if(n==parent[n])
		return n;
	return parent[n]=get(parent[n]);    //path compression 
}
void unite(int x,int y)
{
	int parent1=get(x);
	int parent2=get(y);
	if(parent1!=parent2)
		parent[y]=x;
	else
	{
		c++;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
    int v,e;
    cin>>v>>e;
    make(v);
    for(int i=0;i<e;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	unite(x,y);
    }
    cout<<c;
	return 0;
}
