//Given two non-negative integers N and M
//you have to calculate the sum (F(N) + F(N + 1) + … + F(M)) mod 1000000007.
#include<bits/stdc++.h>
using namespace std;
#define long long long
const long M = 1000000007; // modulo
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

int32_t main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  long t;
  cin>>t;
  while(t--)
  {
    F[0]=F[1]=1;
    long n,m;
    cin>>n>>m;
    n=n+1;
    m=m+2;
    int t1= (n==0 ? 0 : f(n-1));
    int t2= (m==0 ? 0 : f(m-1));
    cout<<(t2-t1+M)%M<<endl;
  }
  return 0;
}


/*

we find s(n)+f[1]= f[n+2];

so s(n)=f[n+2]-1;

s(n,m)=s(m)-s(n-1);
      = f[m+2]-f[n+1];

*/