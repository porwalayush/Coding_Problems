/* the probabbilty of collision in hash is less but collision is possible */

#include<bits/stdc++.h>
using namespace std;
# define int long long
int string_hash(string s)
{
  int p=31,mod=1000000007;
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
int32_t main()
{
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
   #endif

  string text="abababab";
  int d=string_hash(text);
  cout<<d;

}