#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#define ll long long
#define M 1e9 +7
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
    int k;
    cin>>k;
    int p=phi(k);
}