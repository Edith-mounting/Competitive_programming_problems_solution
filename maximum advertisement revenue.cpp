#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    ll k=0;
    ll a[n];
    ll b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++){
        k+=a[i]*b[i];
    }
    cout<<k;
}