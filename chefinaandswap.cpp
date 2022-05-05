#include <iostream>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if((n*(n+1)/2)%2==0){
            ll k=0;
            for(ll i=0;i<n-1;i++){
                for(ll j=i+1;j<n;j++){
                    ll a[n];
                    for(ll ij=0;ij<n;ij++){
                        a[ij]=ij+1;
                    }
                    ll klm=a[i];
                    a[i]=a[j];
                    a[j]=klm;
                    ll sum=0;
                    for(ll ij=0;ij<n;ij++){
                        sum+=a[ij];
                        if(sum*4==(n*(n+1))){
                            k++;
                            break;
                        }
                    }
                }
            }
            cout<<k;
        }
        else{
            cout<<0;
        }
        cout<<"\n";
    }
}