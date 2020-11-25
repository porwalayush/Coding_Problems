#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int findans(int n,int W,int wt[],int val[])
{
    int ks[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0)
            {
              ks[i][j]=0;
            }
            else if(j>=wt[i-1])
            {
               ks[i][j]=max(ks[i-1][j],val[i-1]+ks[i-1][j-wt[i-1]]);
            }
            else
            {
            ks[i][j]=ks[i-1][j];
            }
        }
    }
    return ks[n][W];
}
int main()
{
        int n;
        cin>>n;
        int  W;
        cin>>W;
        int wt[n];
        for(int i=0;i<n;i++)
        {
        cin>>wt[i];
        }
        int val[n];
        for(int i=0;i<n;i++)
        {
        cin>>val[i];
        }
        cout<<findans(n,W,wt,val)<<endl;
    return 0;
}