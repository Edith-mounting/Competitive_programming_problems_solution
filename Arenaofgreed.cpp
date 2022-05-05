#include <iostream>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll count=0;
        while(n>0){
            if(n%2==1){
                n--;
                count++;
                n=n/2;
            }
            else{
                count+=n/2;
                n=n/2;
                if(n%2==1){
                    n--;
                }else{
                    n=n/2;
                }
            }
        }
        cout<<count<<"\n";
    }
}