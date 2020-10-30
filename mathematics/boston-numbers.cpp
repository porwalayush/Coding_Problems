//A Boston number is a composite number, the sum of whose digits 
//is the sum of the digits of its prime factors obtained as a result of prime factorization
// (excluding 1 ). The first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 . 
//For example, 378 = 2 × 3 × 3 × 3 × 7 is a Boston number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7. 
//Write a program to check whether a given integer is a Boston number.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int sod=0;
    int temp=N;
    while(temp)
    {
        sod+=temp%10;
        temp/=10;
    }
    for(int i=2;i*i<=N;i++)
        if(N%i==0)
        {
            int count=0;
            while(N%i==0)
            {
                N/=i;
                count++;
            }
            int sum=0;
            int temp=i;
            while(temp)
            {
                sum+=temp%10;
                temp/=10;
            }
            sod-=sum*count;
        }
    if(N!=1)
    {
        int sum=0;
            int temp=N;
            while(temp)
            {
                sum+=temp%10;
                temp/=10;
            }
        sod-=sum;
    }
    //cout<<sod<<" ";
    cout<<(sod==0);
}