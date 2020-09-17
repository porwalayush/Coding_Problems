#include<bits/stdc++.h>
using namespace std;
# define int long long
void solve(int n,int a[],int &i)
{
    if(n==0 || n==1)
    {
    	a[i]=n;
        i++;
    	return;
    }
    solve(floor(n/2),a,i);
    solve(n%2,a,i);
    solve(floor(n/2),a,i);
    return;
}
int32_t main()
{

    int n,l,r,i=0,j,ans=0;
    cin>>n>>l>>r;
    int a[3*n+1];
    solve(n,a,i);
    for(i=l-1;i<r;i++)
    {
        if(a[i]==1)
        ans++;
    }
    cout<<ans<<endl;
	return 0;
}