#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    while(n--){
        ll n,k;
        cin>>n>>k;
        if(n==1 && k==1){
            cout<<"NO"<<endl;
        }
        if(n>k){
            if(n%2==1){
                if(k%2==1){
                    cout<<"YES"<<endl;
                }
                else cout<<"NO"<<endl;
            }
            else{
                if(k%2==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
}