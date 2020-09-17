#include<bits/stdc++.h>
using namespace std;
void generate(int str[],int i,int l,set<int> &s)
{
	if(i==l)
	{
		int num=0,i=0;
		while(i<l)
		{
			num=num*10+str[i];
			i++;
		}
		s.insert(num);
		return;
	}
	for(int j=i;j<l;j++)
	{
		swap(str[j],str[i]);
		generate(str,i+1,l,s);
		swap(str[j],str[i]);
	}
	return;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[100000],n,temp[100000];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	set<int> s;
	generate(arr,0,n,s);
	for(auto w:s)
		{
		int in=n-1;	
		while(w!=0)
		{
         temp[in]=w%10;
         w=w/10;
         in--;   
		}
		for(int i=0;i<n;i++)
			cout<<temp[i]<<" ";
		cout<<endl;
		}
	return 0;
}



/*#include<bits/stdc++.h>
using namespace std;
void generate(string str,int i,int l,set<string> &s)
{
	if(i==l)
	{
		s.insert(str);
		return;
	}
	for(int j=i;j<l;j++)
	{
		swap(str[j],str[i]);
		generate(str,i+1,l,s);
	}
	return;
}
int main()
{

	string str;
	cin>>str;
	set<string> s;
	generate(str,0,str.length(),s);
	for(auto w:s)
		cout<<w<<endl;
	return 0;
}

*/