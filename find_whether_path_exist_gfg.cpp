#include<bits/stdc++.h>
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
// wens
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
bool dfs_helper(int x,int y,int n,int a[][20],bool visited[][20])
{
  visited[x][y]=true;
  if(x>=n || y>=n)
    return false;
  else if(x<0 || y<0)
    return false;
  else if(a[x][y]==0)
    return false;
  else if(a[x][y]==2)
    return true;
    else
    {
        for(int i=0;i<4;i++)
         {
          if(!visited[x+dx[i]][y+dy[i]])
          {
          bool g=dfs_helper((x+dx[i]),(y+dy[i]),n,a,visited);
          if(g)
            return true;
          }
          }
        }
        return false;
}
void solve()
{ 
  w(t)
  {
    int n,x,y;
    cin>>n;
    int a[20][20];
    f(i,0,n)
    {
      f(j,0,n)
      {
        cin>>a[i][j];
        if(a[i][j]==1)
        {
          x=i;
          y=j;
        }
      }
    }
    bool visited[20][20];
    f(i,0,n)
    {
      f(j,0,n)
      {
        visited[i][j]=false;
      }
    }
  if(dfs_helper(x,y,n,a,visited))
    cout<<1<<endl;
  else
    cout<<0<<endl;
  }  
}
int32_t main()
{
    io();
    solve();
    return 0;
}