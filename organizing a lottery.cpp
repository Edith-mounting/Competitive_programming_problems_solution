#include <iostream>
#define ll long long
using namespace std;
int main(){
    int s,p;
    cin>>s>>p;
    ll a[s],b[s];
    for(int i=0;i<s;i++){
        cin>>a[i]>>b[i];
    }
    ll x[p];
    for(int i=0;i<p;i++){
        cin>>x[i];
    }
    ll count=0;
    for(int i=0;i<p;i++){
        count=0;
        for(int j=0;j<s;j++){
            if(x[i]<=b[j] && x[i]>=a[j]){
                count++;
            }
        }
        cout<<count<<" ";
    }
    cout<<endl;
}