#include<bits/stdc++.h>
using namespace std;
# define ll long long
int solve(int no[],int n,int val)
{
	int ans=0;
	for(int i=1;i<pow(2,n);i++)
	{
		int var=i;
		int pos=0;int ti=0;int prod=1;
       while(var)
       {
       	if(var&1)
       	{
       		prod=prod*no[pos];
       		ti++;
       	}
       	var=var>>1;
       	pos++;
       }
       if(ti&1)
       {
       	ans=ans+(val/prod);
       }
       else
       	ans=ans-(val/prod);
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		int val;
		cin>>val;
		int no[]={2,3,5,7,11,13,17,19};
		int n=sizeof(no)/sizeof(int);
        cout<<solve(no,n,val)<<endl;
	}
	return 0;
}