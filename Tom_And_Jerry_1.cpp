#include <iostream>
#include <cmath>
#define int long long int
using namespace std;
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int a,b,c,d;
        int k;
        cin>>a>>b>>c>>d>>k;
        int x=abs(a-c)+abs(b-d);
        bool bl=false;
        if(k>=x){
            if((k-x)%2==0){
                bl=true;
            }
        }
        if(bl){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }
}