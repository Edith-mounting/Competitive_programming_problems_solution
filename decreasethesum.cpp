#include <iostream>
#define ll long long
#include <cmath>
using namespace std;
ll sum_of(ll n){
    ll p=0;
    while(n>0){
        p+=n%10;
        n=n/10;
    }
    return p;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,s;
        cin>>n>>s;
        ll mn=0;
        ll bl=0;
        ll k=n;
        ll ml=0;
        while(k>1){
            k=k/10;
            ml++;
        }
        bl=pow(10,ml+1);
        if(sum_of(10- n%10 +n)<s){
            mn=10-n%10;
        }else{
        while(sum_of(n)>s){
            if(sum_of(bl)<=s){
                
                break;
            }
            else{
                bl=bl*10;
            }
        }}
        cout<<bl<<"\n";
    }
}