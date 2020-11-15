#include <bits/stdc++.h>
using namespace std;
#define int long long
bool canplace(int stalls[],int m,int cows,int n)
{
    int last=stalls[0];
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        if((stalls[i]-last)>=m)
        {
            last=stalls[i];
            cnt++;
        }
        if(cnt==cows)
            return true;
    }
    return false;
}
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,cows;
        cin>>n>>cows;
        int stalls[n];
        for(int i=0;i<n;i++)
            cin>>stalls[i];
        sort(stalls,stalls+n);
        int s=0;
        int e=stalls[n-1]-stalls[0];
        int ans=0;
        int mid;
        while(s<=e)
        {
            mid=(s+e)/2;
            bool rakhpaaye=canplace(stalls,mid,cows,n);
            if(rakhpaaye)
            {
                ans=mid;
                s=mid+1;
            }
            else
                e=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
