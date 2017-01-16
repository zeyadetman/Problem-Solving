#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int arr[5] = {1,4,3,3 ,2};
  partial_sort(arr,arr+2,arr+5);

    for(int i=0; i<5 ; i++)
        cout<<arr[i]<<" ";

  return 0;
}
