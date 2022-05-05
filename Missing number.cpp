#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n,k=0;
    cin>>n;
    for(int i=0;i<n-1;i++){
        ll a;
        cin>>a;
        k+=a;
    }
    cout<<n*(n+1)/2 -k;
}