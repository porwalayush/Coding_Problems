#include<bits/stdc++.h>
using namespace std;
int lazy[100000]={0};
int query(int ss,int se,int s_tree[],int qs,int qe,int v)
{
	if(lazy[v]!=0)
	{
		s_tree[v]+= lazy[v];
		if(ss!=se)
		{
			lazy[2*v]+=lazy[v];
			lazy[2*v+1]+=lazy[v];
		}
		lazy[v]=0;
	}
	if(qs>se || qe<ss)
    	return INT_MIN;
    if(qs<=ss && qe>=se)
    {
    	return s_tree[v];
    }
    int m=(ss+se)/2;
    int a=query(ss,m,s_tree,qs,qe,2*v);
    int b=query(m+1,se,s_tree,qs,qe,2*v+1);
    return max(a,b);
}
void lazy_update(int ss,int se,int s_tree[],int qs,int qe,int inc,int v)
{
	if(lazy[v]!=0)
	{
		s_tree[v]+= lazy[v];
		if(ss!=se)
		{
			lazy[2*v]+=lazy[v];
			lazy[2*v+1]+=lazy[v];
		}
		lazy[v]=0;
	}
    if(qs>se || qe<ss)
    	return;
    if(qs<=ss && qe>=se)
    {
    	s_tree[v]+=inc;
    	if(ss!=se)
    	{
    		lazy[2*v]+=inc;
    		lazy[2*v+1]+=inc;
    	}
    	return;
    }
    int m=(ss+se)/2;
    lazy_update(ss,m,s_tree,qs,qe,inc,2*v);
    lazy_update(m+1,se,s_tree,qs,qe,inc,2*v+1);
    s_tree[v]=max(s_tree[2*v],s_tree[2*v+1]);
    return;
}
void build(int arr[],int ss,int se,int s_tree[],int v)
{
	if(ss==se)
	{
		s_tree[v]=arr[ss];
		return ;
	}
	int m=(ss+se)/2;
	build(arr,ss,m,s_tree,2*v);
	build(arr,m+1,se,s_tree,2*v+1);
	s_tree[v]=max(s_tree[2*v],s_tree[2*v+1]);
	return;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    
	int arr[]={1,8,5,3,7,2,9};     // 8,15,12,10,7,2,9     // maximum 
	int n=sizeof(arr)/sizeof(int);
	int s_tree[2*n+1];
    build(arr,0,n-1,s_tree,1);
    int q;
    cin>>q;
    lazy_update(0,n-1,s_tree,0,3,7,1);
    while(q--)
    {
    	int l,r;
    	cin>>l>>r;
    	cout<<query(0,n-1,s_tree,l,r,1)<<endl;
    }
	return 0;
}