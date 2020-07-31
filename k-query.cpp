#include<bits/stdc++.h>
using namespace std;
# define N 100000
int a[N];
struct s_tree
{
	vector<int> st[2*N+2];
	void build(int start,int end,int v)
	{
         if(start==end)
         {
            st[v].push_back(a[start]);
            return;
         }
         int mid=(start+end)/2;
         build(start,mid,2*v);
         build(mid+1,end,2*v+1);
         merge(st[2*v].begin(),st[2*v].end(),st[2*v+1].begin(),st[2*v+1].end(),back_inserter(st[v]));
	}
	int query(int start,int end,int l,int r,int v,int k)
	{
		if(r<start||l>end)
			return 0;
		if(l<=start && r>=end)
			return st[v].size()-(lower_bound(st[v].begin(),st[v].end(),k)-st[v].begin());
		int m=(start+end)/2;
		int left=query(start,m,l,r,2*v,k);
		int right=query(m+1,end,l,r,2*v+1,k);
        return left+right;
	}

}tree;

int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>a[i];
	tree.build(0,n-1,1);
	while(q--)
	{
		int ans;
        int l,k;
        cin>>l>>k;
        ans=tree.query(0,n-1,l-1,l-1,1,k);
        cout<<ans<<endl;
	}
	return 0;
}