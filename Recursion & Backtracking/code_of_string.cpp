#include <bits/stdc++.h>
using namespace std;
void gen(string str,char out[],int i,int j)
{
   if(str[i]=='\0')
   {
       out[j]='\0';
       cout<<out;
       return;
   }
   int d=str[i]-'0';
   if(d!=0)
   {
   char ch=d+'a'-1;
   out[j]=ch;
   gen(str,out,i+1,j+1);
   }
   if(str[i+1]!='\0')
   {
       int d2=str[i+1]-'0';
       int d3=d*10+d2;
       if(d3<=26)
       {
           cout<<", ";
       char ch2=d3+'a'-1;
       out[j]=ch2;
       gen(str,out,i+2,j+1);
       }
   }
   return;
}
int main() {
    string s;
    cin>>s;
    char out[100];
    cout<<"[";
    gen(s,out,0,0);
    cout<<"]";
    return 0;
}



// Sample Input
// 1125
// Sample Output
// [aabe, aay, ale, kbe, ky]