#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int find_set(int a, vector<int> &par){
    if(a == par[a]){
        return a;
    }
    return par[a] = find_set(par[a],par);
}
void merg(int a,int b,vector<int>& par,vector<int>& sz){
    a = find_set(a , par);
    b = find_set(b , par);
    if(a==b){
        return ;
    }
    if(sz[a]<sz[b]){
        swap(a,b);
    }
    par[b] = a;
    sz[a]+=sz[b];
}
void solve(){
    int n , q ;
    cin >> n >> q;
    vector<pair<int ,int > > v(n);
    for(int i =0 ;i<n;i++){
        cin >> v[i].first >> v[i].second ;
    }
    sort( v.begin() , v.end());
    vector<pair<int , int>> range;
    range.push_back(v[0]);
    for(int i = 1;i<n;i++){
        if(v[i].first <= range[range.size()-1].second){
            range[range.size()-1].second = max(v[i].second, range[range.size() - 1].second);
        }
        else{
            range.push_back(v[i]);
        }
    }
    vector<int> relax;
    relax.push_back(0);
    for(int i = 0;i<range.size();i++){
        relax.push_back(relax[relax.size()-1] + (range[i].second - range[i].first +1));
    }
    for(int i: relax){
        cout << i << " ";
    }
    cout << "\n";
    int len = relax.size();
    while(q--){
        int k;
        cin>>k;
        if(k > relax[len -1]){
            cout<< -1 <<"\n";
        }
        else{
            auto i = lower_bound(relax.begin(),relax.end(),k);
            int index = (i-relax.begin());
            index --;
            cout<< 
        }
    }
}
int32_t main(){
    int w;
    cin >> w;
    while(w--){
        solve();
    }
}