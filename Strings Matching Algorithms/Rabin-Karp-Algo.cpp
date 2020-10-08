#include<bits/stdc++.h>
using namespace std;
# define int long long
int p=31,mod=1000000007;
int string_hash(string s)
{
  int hash=0;
  int p_pwr=1;
  for(int i=0;i<s.size();i++)
  {
    hash+=((s[i]-'a'+1)*p_pwr);
    p_pwr=(p_pwr*p)%mod;
    hash%=mod;
  }
  return hash;
}
int exp(int a,int b)
{
  int ans=1;
  while(b)
  {
    if(b&1) 
      {
        ans=ans*a;
        ans%=mod;
      }
    a=a*a;
    a%=mod;
    b=b/2;
  }
  return ans;
}
int inv(int a)
{
  return exp(a,mod-2);
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
   #endif

  string text="aaaaaaaaa";
  string pattern="aaa";
  int n= text.size();
  int m= pattern.size();
  int h_pattern=string_hash(pattern);
  int h_now=string_hash(text.substr(0,m));
  if(h_pattern==h_now)
  {
    cout<<0<<endl;
  }
  for(int i=1;i+m<=n;i++)
  {
       h_now=(h_now-(text[i-1]-'a'+1)+mod)%mod;
       h_now*=inv(p);
       h_now%=mod;
       h_now=h_now+((text[i+m-1]-'a'+1)*exp(p,m-1));
       if(h_now==h_pattern)
        cout<<i<<endl;
  }

}