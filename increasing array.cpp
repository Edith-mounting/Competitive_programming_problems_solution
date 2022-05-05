#include <iostream>
#define ll long long 
using namespace std;
int main(){
    ll n,k=0;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]<0){
            k+=a[i-1]-a[i];
            a[i]+=a[i-1]-a[i];
        }
    }
    cout<<k;
}