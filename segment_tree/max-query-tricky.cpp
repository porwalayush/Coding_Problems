// each node of a segment ftree contains a vector
#include<bits/stdc++.h>
using namespace std;
# define N 100000
int a[N];
struct s_tree
{
	vector<int> st[4*N];
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

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	tree.build(0,n-1,1);
	int q;
	cin>>q;
	while(q--)
	{
		int ans;
        int l,r,k;
        cin>>l>>r>>k;
        ans=tree.query(0,n-1,l-1,r-1,1,k);
        cout<<ans<<endl;
	}
	return 0;
}