#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
   #endif
  string text="abcaadfacbbd";
  string pattern="caadf";
  int n= text.size();
  int m= pattern.size();
  for(int i=0;i+m<n;i++)
  {
    if(text.substr(i,m)==pattern)
    {
        cout<<"string match at index "<<i;
        return 0;
    }
  }
  cout<<"no";
}