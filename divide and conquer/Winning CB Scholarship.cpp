#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define endl ("\n")
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define f(i,s,n)        for(int i=s;i<n;i++)
void io()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
bool is_possible(int m,int n,int c,int p,int d)
{
	if((m*p)<=(c+(n-m)*d))
		return true;
		return false;
}
void solve()
{
	int n,c,p,d;
	cin>>n>>c>>p>>d;
	int s=0;
	int e=n;
	int m;
	int ans;
	while(s<=e)
	{
		m=(s+e)/2;
		if(is_possible(m,n,c,p,d))
		{
			ans=m;
			s=m+1;
		}
		else
			e=m-1;
	}
	cout<<ans;
}
int32_t main()
{
	io();
	solve();
	return 0;
}