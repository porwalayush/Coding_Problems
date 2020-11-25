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
int si= 2000005;
void io()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
     #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
 
}
int dp[100][100];
int a[1000];
int sum(int i,int j)
{
    int ans=0;
    for(int k=i;k<=j;k++)
    {
        ans+=a[k];
        ans=ans%100;
    }
    return ans;
}
int mixt(int start,int end)
{
    if(start==end)
        return 0;
    if(dp[start][end]!=-1)
        return dp[start][end];
    dp[start][end]=INT_MAX;
    for(int k=start;k<=end;k++)
    {
        dp[start][end]=min(dp[start][end],(mixt(start,k)+mixt(k+1,end)+(sum(start,k)*sum(k+1,end))));
    }
    return dp[start][end];
}
void solve()
{
    int n;
    while(cin>>n)
    {
        f(i,0,n)
        cin>>a[i];
        memset(dp,-1,sizeof(dp));
        cout<<mixt(0,n-1)<<endl;
    }
}
int32_t main()
{
    io();
    solve();
    return 0;
} 