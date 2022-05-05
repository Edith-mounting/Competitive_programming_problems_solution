#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        ll p=a[n-1];
        for(ll i=0;i<k;i++){
            p+=a[n-i-2];
        }
        cout<<p<<"\n";
    }
    
}