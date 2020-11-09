#include <bits/stdc++.h>
using namespace std;
#define int long long
# define mod 1000000007

int32_t main() {

    int n;
    cin>>n;
    int f[100001]={0},sum[100001]={0};
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        f[num]++;
    }
    for(int i=1;i<=100000;i++)
    {
        for(int j=i;j<=100000;j+=i)
        {
            sum[i]+=f[j];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int r;
        cin>>r;
        cout<<sum[r]<<endl;
    }
    return 0;
}
