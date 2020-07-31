#include <bits/stdc++.h>
using namespace std;

#define long long long
const long M = 1000000007; 
map<long, long> F;
long f(long n) {
  if (F.count(n)) return F[n];
  long k=n/2;
  if (n%2==0) { // n=2*k
    return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
  } else { // n=2*k+1
    return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
  }
}
long query(long ss,long se,long s_tree[],long l,long r,long v)
{
  if(ss>r || se<l)
  {
    return 0;
  }
  if(l<=ss && se<=r)
  {
    return s_tree[v];
  }
  long m=(ss+se)/2;
  long a=query(ss,m,s_tree,l,r,2*v);
  long b=query(m+1,se,s_tree,l,r,2*v+1);
  return __gcd(a,b);
}
void build(long fib[],long ss,long se,long v,long s_tree[])
{
  if(ss==se)
  {
    s_tree[v]=fib[ss];
    return;
  }
  long m=(ss+se)/2;
  build(fib,ss,m,2*v,s_tree);
  build(fib,m+1,se,2*v+1,s_tree);
  s_tree[v]=__gcd(s_tree[2*v],s_tree[2*v+1]);
  return;
}
int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  F[0]=F[1]=1;
  long n,q;
  cin>>n>>q;
  long a[n],fib[n];
  for(long i=0;i<n;i++)
  {
    cin>>a[i];
    if(a[i]==0)
      fib[i]=0;
    else
      fib[i]=f(a[i]-1);
  }
  long s_tree[4*n+1];
  build(fib,0,n-1,1,s_tree);
  while(q--)
  {
    long l,r;
    cin>>l>>r;
    cout<<query(0,n-1,s_tree,l-1,r-1,1)<<endl;

  }
 return 0;
}