#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n,x,k=0;
    cin>>n>>x;
    while(n--){
        char c;
        ll d;
        cin>>c>>d;
        if(c=='+')x+=d;
        else{
            if(x>=d){
                x=x-d;
            }
            else k++;
        }
    }
    cout<<x<<" "<<k;
}