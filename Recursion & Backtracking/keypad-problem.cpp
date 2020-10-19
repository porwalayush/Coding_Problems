#include <iostream>
using namespace std;
char table[][10]= { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void keypad(string str,char out[],int i,int j)
{
    if(str[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    int d=str[i]-'0';
    for(int k=0;table[d][k]!='\0';k++)
    {
        out[j]=table[d][k];
        keypad(str,out,i+1,j+1);
    }
    return;
}
int main() {
    string s;
    cin>>s;
    char out[100];
    keypad(s,out,0,0);
    return 0;
}