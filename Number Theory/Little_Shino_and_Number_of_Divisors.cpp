#include<bits/stdc++.h>
#include<vector>
#include<cmath>

long long p = 1000000007;
using namespace std;

typedef long long ll;

int main()
{

     long long x;
     cin >> x;

     vector<long long> vec;
     vec.resize(x);

     long long nOfDivisors = 1;

     for (long long i = 0; i<x; i++)
     {
          cin >> vec[i];
          nOfDivisors = (nOfDivisors*(vec[i] + 1)) % p;
     }

     long long ans = 1;


     for (long long i = 0; i<x; i++)
     {
          vec[i] = (nOfDivisors*vec[i])%p;
          vec[i] = (vec[i]*500000004)%p;   /*     vec[i]/2      */
          ans = (ans*(vec[i] + 1)) % p;
     }
     
     cout << ans << endl;
     //cin >> x;
     return 0;
}