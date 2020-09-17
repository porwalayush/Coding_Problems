#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
  return (p1.second<p2.second);
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif    
    int t;
    cin>>t;
    pair<int,int> p[10000];
    while(t--)
    {
    	int n;
    	cin>>n;
    	for(int i=0;i<n;i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		p[i]=make_pair(x,y);
    	}
    	sort(p,p+n,cmp);
        int s,e,ans;
        int j=0;
        s=p[j].first;
        e=p[j].first;
        ans=1;
        for(int i=1;i<n;i++)
        {
            if(p[i].first>=p[j].second)
            {
                ans++;
                j=i;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}