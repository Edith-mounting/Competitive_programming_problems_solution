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
int powM(int x,int y,int m){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powM(x,y/2,m);
        return (1ll*t*t)%m;
    }
    else{
        int t=powM(x,y/2,m);
        return ((((1ll*t*t)%m)*x)%m);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,x;
        cin>>a>>b>>x;
        if(b<0){
            int ans=powM(a,phi(x)-1,x);
            b=(-1)*b;
            cout<<powM(ans,b,x)<<"\n";
        }
        else if(b==0){
            cout<<1<<"\n";
        }
        else{
            cout<<powM(a,b,x)<<"\n";
        }
    }
}