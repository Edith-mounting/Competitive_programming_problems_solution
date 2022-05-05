#include <iostream>
#define ll long long
#include <vector>
using namespace std;
int main(){
    ll n;
    cin>>n;
    ll i=1;
    vector<ll> v;
    while(n>0){
        if((n-i)>=0){
            v.push_back(i);
            n=n-i;
        }
        else{
            v[v.size()-1]+=n;
            break;
        }
        i++;
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
