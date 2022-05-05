#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> a;
    ll x=1;
    while(x<1e9 +1){
        a.push_back(x);
        x=x*2;
    }
    while(t--){
        ll al,b;
        cin>>al>>b;
        ll m=0;
        for(int i=0;i<a.size();i++){
            m=max(m,(al^a[i]) + (b^a[i]));
        }
        cout<<m<<"\n";
    }
}