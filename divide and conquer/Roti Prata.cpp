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
 
}
bool is_possible(int mid,int pri[],int c,int p)
{
	int cnt=0;
	for(int i=0;i<c;i++)
	{
		int tmp=pri[i];
		int time=pri[i];
		while(time<=mid)
		{
			cnt++;
			tmp+=pri[i];
			time+=tmp;
		}
	}
	if(cnt>=p)
		return true;
	return false;
}
void solve()
{
	w(t)
	{
	int p,c;
	cin>>p>>c;
	int pri[c];
	f(i,0,c)
	cin>>pri[i];
	int s=0;
	int e=10000000;
	int m;
	int ans;
	while(s<=e)
	{
		m=(s+e)/2;
		if(is_possible(m,pri,c,p))
		{
			ans=m;
			e=m-1;
		}
		else
			s=m+1;
	}
	cout<<ans<<endl;
	}
}
int32_t main()
{
	io();
	solve();
	return 0;
} 