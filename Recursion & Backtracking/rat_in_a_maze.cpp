#include <bits/stdc++.h>
using namespace std;
bool game(char maze[1000][1000],int sol[][1000],int i,int j,int n,int m)
{
    int x,y;
    if(i==n && j==m)
    {
        sol[i][j]=1;
        for(y=0;y<=n;y++)
        {
            for(x=0;x<=m;x++)
            {
                cout<<sol[y][x]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

   if(i>n || j>m)
   return false;
   if(maze[i][j]=='X')
   return false;
   sol[i][j]=1;
   bool right=game(maze,sol,i,j+1,n,m);
   if(right)
   {
       sol[i][j]=0;
       return true;
   }
   else{
   bool down=game(maze,sol,i+1,j,n,m);
   sol[i][j]=0;
   if(down)
   return true;
   else
   return false;
   }
}
int main() {
    char maze[1000][1000];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>maze[i][j];
        }
    }
    int sol[1000][1000]={0};
    bool ya=game(maze,sol,0,0,n-1,m-1);
    if(ya==false)
    cout<<"-1"<<endl;
    return 0;
}