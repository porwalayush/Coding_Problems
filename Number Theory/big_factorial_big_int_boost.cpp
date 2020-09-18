#include <bits/stdc++.h> 
#include <boost/multiprecision/cpp_int.hpp>   /*c++17  */
using boost::multiprecision::cpp_int; 
using namespace std; 
  
cpp_int Factorial(int number) 
{ 
    cpp_int num = 1; 
    for (int i = 1; i <= number; i++) 
        num = num * i; 
    return num; 
} 
  
int main() 
{ 
    int number = 100; 
    cpp_int fact = Factorial(number); 
    cout << fact << endl; 
    return 0; 
} 