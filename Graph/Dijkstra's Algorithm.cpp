#include<bits/stdc++.h>
using namespace std;
# define int long long
int32_t main()
{

  int t;
  cin >> t;
  while (t--)
  {
    int v, e;
    cin >> v >> e;
    unordered_map<int, list<pair<int, int>>> m;
    for (int i = 0; i < e; i++)
    {
      int x, y, w;
      cin >> x >> y >> w;
      m[x].push_back(make_pair(y, w));
      m[y].push_back(make_pair(x, w));
    }
    // for(auto it: m)
    // {
    //   cout<<it.first<<"->";
    //   for(auto x:it.second)
    //     cout<<x.first<<" "<<x.second<<" ";
    //   cout<<endl;
    // }
    int src;
    cin>>src;
    map<int,int> dist;

    for(auto it:m)
      dist[it.first]=INT_MAX;
    set<pair<int,int>> s;
    dist[src]=0;
    s.insert(make_pair(0,src));
    while(!s.empty())
    {
      auto d=*(s.begin());
      int node=d.second;
      int distce=d.first;
      s.erase(s.begin());
      for(auto it:m[node])
      {
          if(it.second+distce<dist[it.first])
          {
            auto p=s.find(make_pair(dist[it.first],it.first));
            if(p!=s.end())
            {
              s.erase(p);
            }

            dist[it.first]=it.second+distce;
            s.insert(make_pair(dist[it.first],it.first));
          }
      }
    }
    for(auto it:dist)
    {
      if(it.first!=src)
      cout<<((it.second==INT_MAX)?-1:it.second)<<" ";
    }
	cout<<endl;
  }
  return 0;
}