#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n,m,a;
    cin>>n>>m>>a;
    ll t=0;
    if(n%a==0){
        t+=n/a;
        if(m%a==0){
            t+=m/a;
        }
        else{
            t+=(m/a)+1;
        }
    }
    else{
        t+=(n/a)+1;
        if(m%a==0){
            t+=m/a;
        }
        else{
            t+=(m/a)+1;
        }
    }
    cout<<t;
}