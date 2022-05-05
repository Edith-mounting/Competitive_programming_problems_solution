#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>b>>a;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    vector<ll> ve;
    ll i=0;
    ll j=0;
    while(i<n){
        j=i+1;
        if(j<n){
            while(v[i].first>=v[j].second && v[i].first<=v[j].first){
                j++;
            }
        }
        ve.push_back(v[i].first);
        i=j;
    }
    /*ll x=v[0].first;
    ve.push_back(x);
    for(ll i=1;i<ve.size();++i){
        if (x <= v[i].second || x >= v[i].first) {
        x = v[i].first;
        ve.push_back(x);
        }
    }*/
    cout<<ve.size()<<endl;
    for(ll i=0;i<ve.size();i++){
        cout<<ve[i]<<" ";
    }
    cout<<endl;
}