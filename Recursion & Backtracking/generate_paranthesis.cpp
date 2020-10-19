#include <iostream>
using namespace std;
void para(int i, int op,int cl,int l,char out[])
{
    if(i==l)
    {
        out[i]='\0';
        cout<<out<<endl;
        return ;
    }
    if(op>cl)
    {
        out[i]=')';
        para(i+1,op,cl+1,l,out);
    }
    if(op<(l/2))
    {
    out[i]='(';
    return para(i+1,op+1,cl,l,out);
    }
    return ;
}
int main() {
    int n;
    cin>>n;
    char out[30];
    para(0,0,0,2*n,out);
    return 0;
}