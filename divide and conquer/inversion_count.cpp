#include <iostream>
using namespace std;
int last(int *a,int f,int l)
{
    int tmp[100000],cnt=0;
    int m=(f+l)/2;
    int i=f;
    int k=f;
    int j=m+1;
    while(i<=m && j<=l)
    {
        if(a[i]>a[j])
        {
            tmp[k++]=a[j++];
            cnt+=m-i+1;
        }
        else
        tmp[k++]=a[i++];
        }
        while(i<=m)
        tmp[k++]=a[i++];
        while(j<=l)
        tmp[k++]=a[j++];
        for(i=f;i<=l;i++)
        a[i]=tmp[i];
        return cnt;
}
int ic(int *a,int f,int l)
{
    if(f>=l)
    return 0;
    int m=(f+l)/2;
    int x=ic(a,f,m);
    int b=ic(a,m+1,l);
    int c=last(a,f,l);
    return x+b+c;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
    int n,a[100000];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<ic(a,0,n-1)<<endl;
	}
    return 0;
}