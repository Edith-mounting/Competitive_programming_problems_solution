#include <iostream>
#define ll long long
#define endl '\n' 
using namespace std;
int main(){
    int t;
    cin>>t; 
    while(t--){
        int n;
        ll x=0;
        cin>>n;
        while(n--){
            int s,v,p,l=0;
            cin>>s>>v>>p;
            l=p/(s+1);
            l=l*v;
            if(l>x){
                x=l;
            }
        }
        cout<<x<<endl;
    }
}