#include<bits/stdc++.h>
using namespace std;
int main()
{
	float x=1.0;
	int people=0;


	float p;
	cin>>p;
	if(p==1.0)
	{
		cout<<366;
		return 0;
	}
	float num=365;
	float deno=365;

	while(x>1-p)
	{
		x=x*(num/deno);
		num--;
		people++;
	}
	cout<<people;
	return 0;
}