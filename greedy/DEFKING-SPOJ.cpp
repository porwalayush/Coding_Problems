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
    w(t)
    {
        int w,h,n;
        cin>>w>>h>>n;
        int x[40005],y[40005];
        f(i,0,n)
        {
            cin>>x[i]>>y[i];
        }
        sort(x,x+n);
        sort(y,y+n);
        int dx=x[0]-1;
        int dy=y[0]-1;
        for(int i=1;i<n;i++)
        {
            dx=max(dx,x[i]-x[i-1]-1);
            dy=max(dy,y[i]-y[i-1]-1);
        }
        dx=max(dx,w-x[n-1]);
        dy=max(dy,h-y[n-1]);
        cout<<dx*dy<<endl;
    }
}


int32_t main()
{
    io();
    solve();
    return 0;
}
