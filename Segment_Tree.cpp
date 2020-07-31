#include<bits/stdc++.h>
using namespace std;
# define int long long
void update_range(int ss,int se,int s_tree[],int inc,int l ,int r,int v)
{
	if(l>se||r<ss)
		return;
	if(se==ss)
	{
		s_tree[v]=s_tree[v]+inc;
		return;
	}
	int m=(ss+se)/2;
	update_range(ss,m,s_tree,inc,l,r,v*2);
	update_range(m+1,se,s_tree,inc,l,r,v*2+1);
	s_tree[v]=min(s_tree[2*v],s_tree[2*v+1]);
	return;
}
void update(int ss,int se,int s_tree[],int inc,int ind,int v)
{
	if(ss>ind || se<ind)
		return;
	if(se==ss)
	{
		s_tree[v]=s_tree[v]+inc;
		return;
	}
	int m=(ss+se)/2;
	update(ss,m,s_tree,inc,ind,v*2);
	update(m+1,se,s_tree,inc,ind,v*2+1);
	s_tree[v]=min(s_tree[2*v],s_tree[2*v+1]);
	return;
}
int query(int ss,int se,int s_tree[],int qs,int qe,int v)
{
   if(qs>se || qe<ss)
   	return INT_MAX;
   if(qs<=ss && qe>=se)
   	return s_tree[v];
   int m=(ss+se)/2;
   int l=query(ss,m,s_tree,qs,qe,v*2);
   int r=query(m+1,se,s_tree,qs,qe,v*2+1);
   return min(l,r);
}
void build(int a[],int i,int j,int v,int *s_tree)
{
	if(i==j)
	{
		s_tree[v]=a[i];
		return ;
	}
		
   int m=(i+j)/2;
   build(a,i,m,v*2,s_tree);
   build(a,m+1,j,v*2+1,s_tree);
   s_tree[v]=min(s_tree[2*v],s_tree[2*v+1]);
   return;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,q,a[100000];
	cin>>n>>q;
    for(int i=0;i<n;i++)
    	cin>>a[i];
    int s_tree[2*n+1];
	build(a,0,n-1,1,s_tree);
    /*
	int a[]={1,9,4,-5,7,3};    // 3,11,6,2,7,3
	int n=sizeof(a)/sizeof(int);
	int s_tree[2*n+1];
	build(a,0,n-1,1,s_tree);
	update(0,n-1,s_tree,7,3,1);
	update_range(0,n-1,s_tree,2,0,2,1);
	int q;
	*/
	while(q--)
	{
		int d,l,r;
		cin>>d>>l>>r;
		if(d==1)
            cout<<query(0,n-1,s_tree,l-1,r-1,1)<<endl;
        else
        	update(0,n-1,s_tree,r,l-1,1);
	}
	return 0;
}