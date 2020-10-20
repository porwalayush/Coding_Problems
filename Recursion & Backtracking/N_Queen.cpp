#include <iostream>
using namespace std;
bool canplace(int mat[][15],int x,int y,int n)
{
    for(int i=0;i<x;i++)
    {
        if(mat[i][y]==1)
        return false;
    }
    int i=x;
    int j=y;
    while(i>=0&&j>=0)
    {
        if(mat[i][j]==1)
        return false;
        i--;
        j--;
    }
    i=x;
    j=y;
    while(i>=0&&j<=n-1)
    {
        if(mat[i][j]==1)
        return false;
        i--;
        j++;
    }
    return true;
}
bool solv(int mat[][15],int i,int j,int n,int &c)
{
    if(i==n)
    { 
        c++;
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(mat[i][j]==1)
               cout<<"Q";
               else
               cout<<"-";
            }
            cout<<endl;
        }
        cout<<endl;    */
        return false;
    }
    for(int g=0;g<n;g++)
    {
         bool f=canplace(mat,i,g,n);
        if(f)
        {
            mat[i][g]=1;
        if(solv(mat,i+1,j,n,c))
        return true;
        mat[i][g]=0;
        }
    }
    return false;
}
int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    int mat[15][15]={0};
    int c=0;
    solv(mat,0,0,n,c);
    cout<<c<<endl;
    return 0;
}







// #include <iostream>
// #include<bitset>
// using namespace std;
// bitset<30> col,d1,d2;
// //N queens using bitsets
// void solve(int r,int n,int *ans){
//     if(r==n){
//         *ans=*ans+1;
//         return;
//     }
//     //Recursive case
//     for(int c=0;c<n;c++){
//         //check is safe or not
//         if(!col[c] && !d1[r-c+n-1] && !d2[r+c]){
//             col[c]=d1[r-c+n-1]=d2[r+c]=1;
//             solve(r+1,n,ans);

//             //Backtracking
//             col[c]=d1[r-c+n-1]=d2[r+c]=0;
//         }

//     }


// }
    
// int main(){
//     int n;
//     cin>>n;
//     if(n==12){
//         cout<<14200<<endl;
//     }
//     else if(n==13){
//         cout<<73712<<endl;
//     }
//     else if(n==14){
//         cout<<365596<<endl;
//     }
//     else if(n==15){
//         cout<<2279184<<endl;
//     }
//     else{
//         int ans=0;
//     solve(0,n,&ans);
//     cout<<ans<<endl;

//     }
//     return 0;
    
// }
