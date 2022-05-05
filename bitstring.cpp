#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    int n,k=2;
    cin>>n;
    ll x=1000000007;
    ll y=1;
    for(int i=1;i<=n;i++){
        y=(y*2)%x;
    }
    cout<<y%x;
}