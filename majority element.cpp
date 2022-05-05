#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    bool b=false;
    int k;
    for(int i=0;i<n;i++){
        auto x = lower_bound(a, a+n, a[i]);
        auto y = upper_bound(a, a+n, a[i]);
        k=y-x;
        if(k>n/2){
            b=true;
            break;
        }
    }
    cout<<b;
}