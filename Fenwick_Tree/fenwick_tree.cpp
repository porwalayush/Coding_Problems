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
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
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
int bit[200005]={0};
void update(int a[],int n,int pos,int inc)
{
  while(pos<=n)
  {
    bit[pos]+=inc;
    pos=pos+(pos&(-pos));
  }
  return;
}
int query(int n)
{
  int ans=0;
  while(n>=1)
  {
     ans+=bit[n];
     n=n-(n&(-n));
  }
  return ans;
}

void solve()
{
  int n,q;
  cin>>n>>q;
  int a[n];
  f(i,0,n)
  {
  cin>>a[i];
  update(a,n,i+1,a[i]);
  }
  while(q--)
  {
    int l,r;
    cin>>l>>r;
    cout<<query(r)-query(l-1)<<endl;
  }
}


int32_t main()
{
    io();
    solve();
    return 0;
}


https://www.youtube.com/watch?v=DxN5-Y8Ld4c