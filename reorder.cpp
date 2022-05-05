#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#define ll long long
#define M 1000000007
using namespace std;
int phi(int x) {
  int p = x;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      p = p / i * (i - 1);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    p = p / x * (x - 1);
  }
  return p;
}
int main(){
    int n,k,pos;
    cin>>n>>k>>pos;
    ll count=1;
    for(int i=1;i<=n-1;i++){
        count=(count*i)%M;
    }
    count=count%M;
    cout<<count<<"\n";
}