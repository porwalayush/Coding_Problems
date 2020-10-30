#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string s1,s2;
  getline(cin,s1);
  getline(cin,s2);
  int f1[256]={0},f2[256]={0};
  int l1=s1.length();
  int l2=s2.length();
  for(int i=0;s2[i];i++)
  {
    f2[s2[i]]++;
  }
  int cnt=0;
  int start=0;
  int min_len=INT_MAX,starting=-1;
  for(int i=0;s1[i];i++)
  {
    char cur=s1[i];
    f1[cur]++;


    if(f2[cur]!=0 and f2[cur]>=f1[cur])
        cnt++;


    if(cnt==l2)
    {
        char tmp=s1[start];

        while(f2[tmp]==0 || f1[tmp]>f2[tmp])
        {
            f1[tmp]--;
            start++;
            tmp=s1[start];
        }
        int window_length=i-start+1;
    if(min_len>window_length)
    {
        min_len=window_length;
        starting=start;
    }
    }
  }
  if(min_len==INT_MAX)
    cout<<"No String";
else
{
  string ans=s1.substr(starting,min_len);
  cout<<ans;
}
  return 0;
}