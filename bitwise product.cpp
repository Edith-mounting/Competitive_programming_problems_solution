#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,y,l,r;
        int n=0;
        cin>>x>>y>>l>>r;
        bool b=false;
        while(r>=pow(2,n)-1){
            if(r==pow(2,n)-1){
                b=true;
            }
            n++;
        }
        if(b){
            cout<<r<<endl;
        }
        else{
            if(l<=pow(2,n-1)-1){
                ll k=pow(2,n-1)-1;
                ll s=pow(2,n-2)-1;
                while(1){
                    k=pow(2,n-1)-1;
                    s=pow(2,n-2)-1;
                    if((x&s)*(y&s)!=(x&k)*(y&k)){
                        break;
                    }
                    n--;
                }
                cout<<k<<endl;
            }
            else{
               cout<<r<<endl;
            }
        }
    }
}