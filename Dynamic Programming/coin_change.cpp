#include<bits/stdc++.h>
using namespace std;
// topdown dp
int minchange(int amount,int coin[],int n)
{
	if(amount<=0)
		return 0;
	int r=INT_MAX;
   for(int i=0;i<n;i++)
   {
   	if(coin[i]<=amount)
   		r=min(r,minchange(amount-coin[i],coin,n)+1);
   }
   return r;
}
// bottom up dp
int bu(int amount,int coin[],int n)
{
	int dp[amount+1];
	dp[0]=0;
   for(int i=1;i<=amount;i++)
   {
    int h=INT_MAX;
   	for(int j=0;j<n;j++)
   	{
   		if(coin[j]<=i)
      {
   			h=min(h,(dp[i-coin[j]]+1));
      }
   	}
    dp[i]=h;
   }
   cout<<dp[1]<<" ";
   return dp[amount];
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int n;
    cin>>n;
    int coin[n];
    for(int i=0;i<n;i++)
    	cin>>coin[i];
    int amount;
    cin>>amount;
    cout<<minchange(amount,coin,n)<<endl;
    cout<<bu(amount,coin,n);
	return 0;
}