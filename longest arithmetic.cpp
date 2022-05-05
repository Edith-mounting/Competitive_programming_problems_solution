#include <iostream>
#define ll long long 
using namespace std;
int main(){
    int t,tl;
    cin>>t;
    tl=t;
    while(t--){
        int n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        ll p=2,q=a[1]-a[0],m=2;
        for(int i=1;i<n-1;i++){
            if(a[i+1]-a[i]==q){
                m++;
            }else{
                if(m>p){
                    p=m;
                }
                m=2;
                q=a[i+1]-a[i];
            }
        }
        if(m>p){
            p=m;
        }
        cout<<"Case #"<<tl-t<<":"<<p<<"\n";
    }
}