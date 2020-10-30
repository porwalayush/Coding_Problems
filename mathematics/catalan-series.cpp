//Print the catalan number at position N.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
        ll i,j,k,n,m,ans=0,cnt=0,sum=0;  
        cin>>n;
        ll catalan[n+1];
        catalan[0]=catalan[1]=1;
        for(i=2;i<=n;i++){
          catalan[i]=0;
          for(j=0;j<i;j++){
            catalan[i]+=catalan[j]*catalan[i-j-1];
          }
        }
        // for(i=0;i<=n;i++){
        //     cout<<i<<" "<<catalan[i]<<'\n';                   
        // }
        cout<<catalan[n];
}
