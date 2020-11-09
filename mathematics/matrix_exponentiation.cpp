//SEQ SPOJ
#include<bits/stdc++.h>
using namespace std;
#define int long long
# define mod 1000000000
int k;
vector<int> a,b,c;

vector<vector<int> > multiply(vector<vector<int> > a1,vector<vector<int> > b1)
{
	vector<vector<int> > c1(k+1, vector<int>(k+1));
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int x=1;x<=k;x++)
			{
				c1[i][j]=(c1[i][j]+(a1[i][x]*b1[x][j])%mod)%mod;
			}
		}
	}
	return c1;
}

vector<vector<int> > pow(vector<vector<int> > T, int p)
{
	if(p==1)
		return T;
	if(p&1)
		return (multiply(T,pow(T,p-1)));
	vector<vector<int> > X=pow(T,p/2);
	return multiply(X,X);
}

int compute(int n)
{
	if(n==0)
		return 0;
	if(n<=k)
		return b[n-1];
	//step 1
	vector<int> f1(k+1);
	for(int i=1;i<=k;i++)
		f1[i]=b[i-1];
	// step 2
	vector<vector<int> > T(k+1, vector<int>(k+1));
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i<k)
			{
				if(i+1==j)
					T[i][j]=1;
				else
					T[i][j]=0;
			}
			else
			{
				T[i][j]=c[k-j];
			}
		}
	}

	// step 3
	T=pow(T,n-1);

	//step 4
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		ans=(ans+(T[1][i]*f1[i])%mod)%mod;
	}
	return ans;
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
    	cin>>k;
    	for(int i=0;i<k;i++)
    	{
    		int num;
    		cin>>num;
    		b.push_back(num);
    	}
    	for(int i=0;i<k;i++)
    	{
    		int num;
    		cin>>num;
    		c.push_back(num);
    	}
    	int n;
    	cin>>n;
    	cout<<compute(n)<<endl;
    	b.clear();
    	c.clear();
    }  
    return 0;
}
