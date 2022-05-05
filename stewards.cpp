#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;
int main(){
    int n,k=0;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n-1;i++){
        if(a[i]>a[0] && a[i]<a[n-1]){
            k++;
        }
    }
    cout<<k;
}