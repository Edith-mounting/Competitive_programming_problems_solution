#include <iostream>
using namespace std;
#define ll long long
int main(){
    ll a[4];
    a[0]=0;
    a[1]=0;
    a[2]=0;
    a[3]=0;
    ll t;
    cin>>t;
    a[0]=t;
    for(int i=1;i<4;i++){
        ll p;
        cin>>p;
        bool q=true;
        for(int j=0;j<i;j++){
            if(a[j]==p){
                q=false;
            }
        }
        if(q){
            a[i]=p;
        }
    }
    int k=0;
    for(int i=0;i<4;i++){
        if(a[i]==0)k++;
    }
    cout<<k;
}