#include<iostream>
# include<queue>
using namespace std;
# define ll long long
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin>>n;
	int a[n];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	ll k;
	cin>>k;
	priority_queue<ll> pq;
	ll i=0;
	while(i<n)
	{
	if(i<k)
	{
		pq.push(a[i]);
		if(i==k-1)
		cout<<pq.top()<<" ";
		
	}
	else if(a[i]>pq.top())
	{
		pq.pop();
			pq.push(a[i]);
		cout<<pq.top()<<" ";
		
	}
	else
		cout<<pq.top()<<" ";
	i++;
    }
	return 0;
}