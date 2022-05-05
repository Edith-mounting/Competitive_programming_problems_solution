#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n,x=0,y=0;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0){
            x++;
        }
        if(a[i]==0){
            y++;
        }
    }
    ll k=0;
    for(int i=0;i<n;i++){
        if(a[i]<=-1){
            k+=-1-a[i];
        }
        else if(a[i]>=1){
            k+=a[i]-1;
        }
    }
    if(y==0){
        k+=2*(x%2);
    }
    else{
        k+=y;
    }
    cout<<k;
}