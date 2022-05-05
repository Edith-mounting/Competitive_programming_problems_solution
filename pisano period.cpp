#include <iostream>
#define ll long long
using namespace std;
ll get_pisano_period(ll m) {
    ll a = 0, b = 1, c = a + b;
    for (ll i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}
int main(){
    ll n,k,c=0;
    ll m;
    cin>>n>>m;
    k=get_pisano_period(m);
    //cout<<k;
    ll x=n%k;
    if(x==0){
        cout<<0;
    }
    else if(x==1){
        cout<<1;
    }
    else{
        long long a=0,b=1;
        for(int i=0;i<x-1;i++){
            c=a%m+b%m;
            a=b%m;
            b=c%m;
        }
        cout<<c%m;
    }
}