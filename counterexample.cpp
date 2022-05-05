#include <iostream>
#define ll long long 
using namespace std;
int main(){
    ll l,r;
    cin>>l>>r;
    if((r-l)<2){
        cout<<-1;
    }
    else{
        if(l%2==1){
            if(r-l==2){
                cout<<-1;
            }
            else{
                cout<<l+1<<" "<<l+2<<" "<<l+3;
            }
        }
        else cout<<l<<" "<<l+1<<" "<<l+2;
    }
}