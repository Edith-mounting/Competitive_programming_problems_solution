#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll c1=0,c2=0;
    for(int i=n-1;i>=0;i--){
        if(c1<=c2){
            c1+=a[i];
        }
        else{
            c2+=a[i];
        }
    }
    if(c1>c2){
        cout<<c1-c2<<"\n";
    }
    else{
        cout<<c2-c1<<"\n";
    }
}