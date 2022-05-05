#include <iostream>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll dif=0;
        ll k=0;
        if(a>b){
            dif=a-b;
            if((a-b)%10==0){
                k+=(a-b)/10;
            }
            else{
                k+=(a-b)/10 +1;
            }
        }
        else{
            dif=b-a;
            if(dif%10==0){
                k+=dif/10;
            }else{
                k+=dif/10 +1;
            }
        }
        cout<<k<<"\n";
    }
}