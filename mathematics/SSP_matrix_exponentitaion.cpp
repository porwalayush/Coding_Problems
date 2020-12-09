#include<bits/stdc++.h>

#define ll long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const ll N=100005;

ll mod;

void mul(ll a[20][20],ll b[20][20],ll k){
    ll ml[20][20];
    memset(ml,0,sizeof(ml));
    ll i,j,z;
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            for(z=0;z<k;z++){
                ml[i][j]+=a[i][z]*b[z][j];
                ml[i][j]%=mod;
            }
        }
    }
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            a[i][j]=ml[i][j];
        }
    }
}

void power(ll tobepowered[20][20],ll n,ll k){
    ll res[20][20];
    memset(res,0,sizeof(res));
    for(ll i=0;i<k;i++){
        for(ll j=0;j<k;j++){
            if(i==j) res[i][j]=1;
        }
    }
    while(n){
        if(n&1) mul(res,tobepowered,k);
        mul(tobepowered,tobepowered,k);
        n/=2;
    }
    ll i,j;
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            tobepowered[i][j]=res[i][j];
        }
    }
}

ll giveans(ll a[],ll b[],ll c[],ll k,ll here){
    ll tobepowered[20][20];
    memset(tobepowered,0,sizeof(tobepowered));
    ll i,j;
    tobepowered[0][0]=1;
    tobepowered[0][1]=0; 
    tobepowered[1][1]=1;
    tobepowered[1][2]=1;
    for(i=0;i<k;i++){
        tobepowered[0][i+2]=c[i];
        tobepowered[2][i+2]=c[i];
    }
    for(i=3;i<k+2;i++){
        for(j=0;j<k+2;j++){
            if(j+1==i){
                tobepowered[i][j]=1;
            }
        }
    }
    power(tobepowered,here-k,k+2);
    ll ans=0,sum=0;
    for(i=0;i<k;i++){
        ans+=tobepowered[0][i+2]*a[0];ans%=mod;
    }
    for(i=0;i<k;i++){
        sum+=c[i];sum%=mod;
    }
    ans+=tobepowered[0][0]*a[0]*sum;
    return ans;
}

ll sumtill(ll a[],ll b[],ll c[],ll k,ll here){
    ll sum=0,i;
    if(here<=k){
        for(i=0;i<here;i++){
            sum+=a[i];sum%=mod;
        }
        return sum;
    }   
    else{
        ll sum2=giveans(a,b,c,k,here)%mod;
        return sum2;
    }   
}

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,k,n,m,ans=0,cnt=0,sum=0;  
        cin>>k;
        ll b[k]={},c[k]={};
        ll a[k]={};
        for(i=0;i<k;i++){
            cin>>b[i];
            a[i]=b[i];
        }
        for(i=0;i<k;i++){
            cin>>c[i];
        }  
        ll l,r;
        cin>>l>>r>>mod;
        cout<<(sumtill(a,b,c,k,r)-sumtill(a,b,c,k,l-1)+mod)%mod<<'\n';
    }
}