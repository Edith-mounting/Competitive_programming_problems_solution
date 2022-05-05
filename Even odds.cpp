#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    cin>>n>>k;
    if(n%2==1){
        if(k>(n/2)+1){
            k=k-(n/2)-1;
            cout<<k*2;
        }
        else{
            cout<<2*k-1;
        }
    }
    else{
        if(k>n/2){
            k=k-(n/2);
            cout<<k*2;
        }
        else cout<<2*k-1;
    }
}
