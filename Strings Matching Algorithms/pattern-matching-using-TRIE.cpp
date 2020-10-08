#include<bits/stdc++.h>
using namespace std;
struct trie{
    trie *nxt[26];
    trie()
    {
    for(int i=0;i<26;i++)  nxt[i]=NULL;
    }
};
trie *root;
void insert(string s)
{
    trie *cur= root;
    for(int i=0;i<s.size();i++)
    {
        if(cur->nxt[s[i]-'a']==NULL)   cur->nxt[s[i]-'a'] = new trie();
        cur= cur->nxt[s[i]-'a'];
    }
}
bool in_trie(string s)
{
    trie *cur= root;
    for(int i=0;i<s.size();i++)
    {
        if(cur->nxt[s[i]-'a']==NULL)   return false;
        cur= cur->nxt[s[i]-'a'];
    }
    return true;
}
int main()
{
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
   #endif


  root= new trie();
  string text="abcaadfacbbd";
  string pattern="caadf";
  int n= text.size();
  int m= pattern.size();


  for(int i=0;i<n;i++)
  {
    insert(text.substr(i));      /*  store all the sufiixx staring from i*/
  }


  if(in_trie(pattern))
  {
    cout<<"yes";
  }
  else
    cout<<"NO";

}