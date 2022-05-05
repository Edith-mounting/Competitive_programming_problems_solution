#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<1;
    }
    else if(n==2 || n==3){
        cout<<"NO SOLUTION";
    }
    else{
        if(n%2==0){
            ll x=1;
            for(ll i=n/2+1;i<n+1;i++){
                cout<<i<<" "<<x<<" ";
                x++;
            }
        }
        else{
            ll x=1;
            for(ll i=n/2+1;i<n;i++){
                cout<<i<<" "<<x<<" ";
                x++;
            }
            cout<<n;
        }
    }
}