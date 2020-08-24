#include<bits/stdc++.h>
using namespace std;
// using recursion
int solve(int n,int c)
{
	if(n==1)
		return 0;
	if(n%2==0 && n%3==0)
		return min(solve(n/3,c+1),min(solve(n/2,c+1),solve(n-1,c+1)))+1;
	else if(n%2==0)
		return min(solve(n/2,c+1),solve(n-1,c+1))+1;
	else if(n%3==0)
		return min(solve(n/3,c+1),solve(n-1,c+1))+1;
	else
		return solve(n-1,c+1)+1;
}
// using top down dp with memorization
int td(int n,int c,int dp[])
{
	if(n==1)
		return 0;
	if(dp[n]!=0)
		return dp[n];
	else if(n%2==0 && n%3==0)
		return dp[n]=min(td(n/3,c+1,dp),min(td(n/2,c+1,dp),td(n-1,c+1,dp)))+1;
	else if(n%2==0)
		return dp[n]=min(td(n/2,c+1,dp),td(n-1,c+1,dp))+1;
	else if(n%3==0)
		return dp[n]=min(td(n/3,c+1,dp),td(n-1,c+1,dp))+1;
	else
		return dp[n]=td(n-1,c+1,dp)+1;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int n;
    cin>>n;
    int dp[110]={0};
    cout<<(td(n,0,dp))+1;
	return 0;
}