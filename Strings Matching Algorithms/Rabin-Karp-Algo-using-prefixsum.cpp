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

  string text="abacabadhaba";
  string pattern="aba";
  int n= text.size();
  int m= pattern.size();
  int h_pat=string_hash(pattern);
  int pref[n];
  for(int i=0;i<n;i++)
  {
    pref[i]=((text[i]-'a'+1)*exp(p,i));
    pref[i]%=mod;
  }
  for(int i=1;i<n;i++)
  {
      pref[i]+=pref[i-1];
      pref[i]%=mod;
  }

   for(int i=0;i+m<=n;i++)
   {
    /*  l=i   r= i+m-1   */
    int h_now= pref[i+m-1];
    if(i-1>=0) 
      {
        h_now-=pref[i-1];
        h_now+=mod;
        h_now%=mod; 
      }
      if((h_pat*exp(p,i))%mod==h_now)
      {
        cout<<i<<endl;
      }
   }
}