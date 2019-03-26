//https://projecteuler.net/problem=48

#include <iostream>
using namespace std; 
long mod =10000000000;
int main() {
  long x = 0;
  for(int i=1; i<=1000; i++) {
    long a = i;
    for(int j=1;j<i;j++) {
       a*= i;
       a%= mod;
    }
    x+= a;
    x%= mod;
  }
  cout<<x;
}
