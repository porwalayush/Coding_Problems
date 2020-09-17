#include<bits/stdc++.h>
using namespace std;
# define int long long
# define max 3000000
int a[max];
int s_tree[4*max];
void build(int ss,int se,int v)
{
	if(ss==se)
	{
       s_tree[v]=a[ss];
       return;
	}
	int m=(ss+se)/2;
	build(ss,m,2*v);
	build(m+1,se,2*v+1);
	int d=log2(se-ss+1);
	if(d&1)
		s_tree[v]=s_tree[2*v]|s_tree[2*v+1];
	else
		s_tree[v]=s_tree[2*v]^s_tree[2*v+1];
	return;
}
void update(int ss,int se,int pos,int val,int v)
{
	if(ss>pos||se<pos)
		return;
	if(ss==se)
	{
		s_tree[v]=val;
		return;
	}
		
	int m=(ss+se)/2;
	update(ss,m,pos,val,2*v);
	update(m+1,se,pos,val,2*v+1);
	int d=log2(se-ss+1);
	if(d&1)
		s_tree[v]=s_tree[2*v]|s_tree[2*v+1];
	else
		s_tree[v]=s_tree[2*v]^s_tree[2*v+1];
	return;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n,k;
  cin>>n>>k;
  n=pow(2,n);
  for(int i=0;i<n;i++)
  	cin>>a[i];
  build(0,n-1,1);
  while(k--)
  {
  	int x,y;
     cin>>x>>y;
     update(0,n-1,x-1,y,1);
     cout<<s_tree[1]<<endl;
  }
	return 0;
}