#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<int> v[N];
void euler_tour1(int cur,int par)
{
  cout<<cur<<" ";
  for(auto x: v[cur])
  {
    if(x!=par)
    {
      euler_tour1(x,cur);
      cout<<cur<<" ";
    }
  }
}
void euler_tour2(int cur,int par)
{
  cout<<cur<<" ";
  for(auto x: v[cur])
  {
    if(x!=par)
    {
      euler_tour2(x,cur);
    }
  }
  cout<<cur<<" ";
}
void euler_tour3(int cur,int par)
{
  cout<<cur<<" ";
  for(auto x: v[cur])
  {
    if(x!=par)
    {
      euler_tour3(x,cur);
    }
  }
}
int tin[N],tout[N],timer;
void euler_tour3_with_times(int cur,int par)
{
  tin[cur]=++timer;
  for(auto x: v[cur])
  {
    if(x!=par)
    {
      euler_tour3_with_times(x,cur);
    }
  }
  tout[cur]=timer;
}
bool is_ancestor(int x,int y)
{
  return tin[x]<=tin[y] && tout[x]>=tout[y];
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
  euler_tour1(1,0);   /*  O(2*n-1) space  */
  cout<<endl;
  euler_tour2(1,0);    /*  O(2*n) space  */
  cout<<endl;
  euler_tour3(1,0);    /*  O(n) space  */
  timer=0;
  cout<<endl;
  euler_tour3_with_times(1,0);
  for(int i=1;i<=n;i++)
  {
    cout<<i<<" "<<tin[i]<<" "<<tout[i]<<endl;
  }
  int x,y;
  cin>>x>>y;
  if(is_ancestor(x,y))   /* x is the ancextor of y or not */
  {
    cout<<"YES"<<endl;
  }
  else
    cout<<"NO"<<endl;
  return 0;
}