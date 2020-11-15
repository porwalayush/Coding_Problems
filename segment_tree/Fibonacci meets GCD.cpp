// 3 2
// 2 4 8
// 1 3
// 2 3
// Sample Output
// 1
// 3
// Explanation
// F(2) = 1 , F(4) = 3 , F(8) = 21
// For query 1, gcd(1,3,21) = 1
// For query 2, gcd(3,21) = 3
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)

#define	matrix	vector<vector<ll>>

matrix	mul(matrix  &A,matrix B){
    matrix C(2,vector<ll>(2));
    for(int	i=0;i<2;i++){
        for(int	j=0;j<2;j++){
            for(int	x=0;x<2;x++)
                C[i][j]=(C[i][j]+A[i][x]*B[x][j])%MOD;
        }
    }
    return	C;
}

matrix	pow(matrix A,ll p){
    if(p==1)
        return	A;
    if(p&1)
        return	mul(A,pow(A,p-1));
    matrix	X=pow(A,p/2);
    return	mul(X,X);
}

ll	fib(ll	n){
    if(!n)
        return	0;
    if(n==1||n==2)
        return 1;
    vector<ll>	F1(2);
    F1[0]=F1[1]=1;
    matrix	T(2,vector<ll>(2));
    T[0][0]=0;
    T[0][1]=T[1][0]=T[1][1]=1;
    T=pow(T,n-1);
    ll	res=0;
    for(int	i=0;i<2;i++){
        res=(res+T[0][i]*F1[i])%MOD;
    }
    return	res%MOD;
}


ll gcd(ll a,ll b){
    if(a==-1)
        return b;
    if(b==-1)
        return a;
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void buildTree(ll *inp,ll *tree,ll ss,ll se,ll index){
    if(ss==se){
        tree[index]=inp[ss];
        return;
    }
    ll mid=(ss+se)/2;
    buildTree(inp,tree,ss,mid,2*index);
    buildTree(inp,tree,mid+1,se,2*index+1);
    tree[index]=gcd(tree[2*index],tree[2*index+1]);
    return;
}

ll query(ll *tree,ll ss,ll se,ll qs,ll qe,ll index){
    if(ss>qe || se<qs)
        return -1;
    if(ss>=qs && se<=qe)
        return tree[index];
    ll mid=(ss+se)/2;
    ll lAns=query(tree,ss,mid,qs,qe,2*index);
    ll rAns=query(tree,mid+1,se,qs,qe,2*index+1);
    return gcd(lAns,rAns);
}


int main(){
ll inp[100001];
ll n,q;
sl(n);sl(q);
ll tree[4*n+1];
for(ll i=1;i<=n;++i)
    sl(inp[i]);
buildTree(inp,tree,1,n,1);
while(q--){
    ll qs,qe;
    sl(qs);sl(qe);
    cout<<fib(query(tree,1,n,qs,qe,1))%MOD<<endl;
}
return 0;
}
