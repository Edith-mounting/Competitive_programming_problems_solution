#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define int             long long
int32_t main(){
    int n,k;
    cin>>n>>k;
    vector<pii> a(n);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a.pb({k,i+1});
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    cout<<a[k-1].ff<<"\n";
    vi x;
    for(int i=0;i<k;i++){
        x.pb(a[i].ss);
    }
    sort(x.begin(),x.end());
    for(auto i:x){
        cout<<i<<" ";
    }
    cout<<"\n";
}