#include<bits/stdc++.h>
using namespace std;
// using recursion
int fib(int n)
{
	if(n==0 || n==1)
		return n;
	else
		return fib(n-1)+fib(n-2);
}
// using topdown dp
int td(int n,int dp[])
{
	if(n==0)
		return dp[0];
	if(dp[n]!=0)
		return dp[n];
	else
	{
		return dp[n]=td(n-1,dp)+td(n-2,dp);
	}
}
// using bottomup approach
int bu(int n)
{
	int dp[n]={0};
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

// space optimized bottom up
int buspace(int n)
{
	int a=0;
	int b=1;
	int c;
	for(int i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}
 
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int n;
    cin>>n;
    int dp[100]={0};
    dp[1]=1;
    cout<<buspace(n)<<endl;
	return 0;
}