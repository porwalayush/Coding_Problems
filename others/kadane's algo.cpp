#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int ans=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+a[i];
            ans=max(ans,sum);
            if(sum<0)
                sum=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
