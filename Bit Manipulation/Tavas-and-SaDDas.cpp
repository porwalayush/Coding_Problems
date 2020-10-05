#include<bits/stdc++.h>
using namespace std;
# define int long long
int32_t main() {
	string s;
	cin>>s;
	int l=s.length();
	int ans=(1<<l)-2;
	for(int i=l-1,pos=0;i>=0;i--,pos++)
	{
       if(s[i]=='7')
	   {
		   ans+=(1<<pos);
	   }
	}
	cout<<ans+1<<endl;
	return 0;
}