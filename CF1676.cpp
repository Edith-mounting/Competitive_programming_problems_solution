#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    ll ax[32];
    ax[0]=1;
    for(int i=1;i<32;i++){
        ax[i]=pow(2,i);
    }
    int t;
    cin>>t;
    while(t--){
        ll k=0;
        ll a,b;
        cin>>a>>b;
        k=a^ax[0] +b^ax[0];
        for(int i=1;i<32;i++){
            if(a^ax[i] + b^ax[i]<k){
                k=a^ax[i] +b^ax[i];
            }
        }
        cout<<k<<"\n";
    }
}