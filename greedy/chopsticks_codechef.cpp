#include<bits/stdc++.h>
using namespace std;

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
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define f(i,s,n)        for(int i=s;i<n;i++)
void io()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

void solve()
{
    int n,d;
    cin>>n>>d;
    int a[n];
    f(i,0,n)
    cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        if((a[i+1]-a[i])<=d)
        {
            ans++;
            i++;
        }
    }
    cout<<ans<<endl;
}


int32_t main()
{
    io();
    solve();
    return 0;
}
