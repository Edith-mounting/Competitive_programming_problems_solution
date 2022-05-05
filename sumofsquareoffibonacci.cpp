#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    if(n==0){
        cout<<0;
    }
    else if(n==1){
        cout<<1;
    }
    else{
        ll m=n-1;
        ll x=0,y=0;
        n=n%60;
        m=m%60;
        if(m==0){
            x=0;
        }
        else if(m==1){
            x=1;
        }
        else{
            int a=1,b=1;
            for(int i=0;i<m-1;i++){
                x=a%10 + b%10;
                a=b%10;
                b=x%10;
            }
            x=x%10;
        }
        if(n==0){
            y=0;
        }
        else if(n==1){
            y=1;
        }
        else{
            int a=1,b=1;
            for(int i=0;i<n-1;i++){
                y=a%10 + b%10;
                a=b%10;
                b=y%10;
            }
            y=y%10;
        }
        cout<<(x*y)%10;
    }
}