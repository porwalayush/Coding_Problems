/*we want to find the min value in the subtree of x*/
#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<int> v[N];
int dp[N];
void dfs(int cur,int par)
{
  dp[cur]=cur;
  for(auto s: v[cur])
  {
    if(s!=par)
    {
      dfs(s,cur);
      dp[cur]=min(dp[cur],dp[s]);
    }
  }
  return;
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1,0);
  for(int i=1;i<=n;i++)
  {
    cout<<i<<" "<<dp[i]<<endl;
  }
  return 0;
}