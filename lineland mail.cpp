#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<n;i++){
        if(i==0){
            cout<<a[1]-a[0]<<" ";
            cout<<a[n-1]-a[0]<<endl;
        }
        else if(i==n-1){
            cout<<a[i]-a[n-2]<<" ";
            cout<<a[i]-a[0]<<endl;
        }
        else{
            if(a[i]-a[i-1]>a[i+1]-a[i]){
                cout<<a[i+1]-a[i]<<" ";
                if(a[n-1]-a[i]>a[i]-a[0]){
                    cout<<a[n-1]-a[i]<<endl;
                }
                else{
                    cout<<a[i]-a[0]<<endl;
                }
            }
            else{
                cout<<a[i]-a[i-1]<<" ";
                if(a[n-1]-a[i]>a[i]-a[0]){
                    cout<<a[n-1]-a[i]<<endl;
                }
                else{
                    cout<<a[i]-a[0]<<endl;
                }
            }
        }
    }
}