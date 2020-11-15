// He is allowed to select n marbles.
// There are marbles of k different colors. From each color,
// there are also infinitely many marbles. 
// Hänschen wants to have at least one marble of each color, 
// but still there are a lot of possibilities for his selection.

// he can slelect n marbles and want k different color marble
// so first filled take 1 marble of k type now we can take (n-k) marbles
// take m=n-k marbles from k type 
// star and bars concept WE HAVE TO FIND m stars and k-1 bars
// m+k-1 place k-1 bars so ans = (m+k-1)C(k-1) put m value= (n-1)C(k-1) 

#include<stdio.h>
#include<math.h>
long long int C(long long int n,long long int r) {
  long long int i,j=1,k=1,res = 1;
  if(r> n/2)
    r = n-r;
 
  for(i = 0;i<r;i++) {

 
 
    res *=  n--;
    res /= i+1;
 
  }
  return res; 
}
 
 
int main(int argc,char** argv) {
  int T; 
  long long int N, K;
 
  scanf("%d",&T);
  while(T--) {
    scanf("%lld %lld",&N,&K);
   printf("%lld\n", C(N-1,K-1));
  }
  return 0;
}