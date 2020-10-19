#include<bits/stdc++.h>
using namespace std;
int main () {
	int a,b;
    cin>>a>>b;
    int p=a^b;
    int d=log2(p)+1;
    int r=pow(2,d)-1;
    cout<<((r>0)?r:0);
	return 0;
}