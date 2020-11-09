#include <iostream>
using namespace std;
#define ll long long int 

ll mod(string c,int a){
    ll num=0;
    for(int i=0;i<c.size();i++){
        num=((num*10)+(c[i]-'0'))%a;
    }
    return num;
}

ll gcd(ll a,ll b){
    if(b==0)
    return a;
    return gcd(b,a%b);
}

int main() {
    ll a,b;
    string c;
    cin>>a>>c;
    if(a==0){
        cout<<c;
    }
    else{
        b=mod(c,a);
        if(a>b){
            swap(a,b);
        }
        ll ans=1;
        ans=gcd(a,b);
        cout<<ans;
    }
}
