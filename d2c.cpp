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
    int n;
    cin>>n;
    vector<int> par(n+1);
    vector<int> sz(n+1);
    if(n==1){
        cout<<1;
        return ;
    }
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    vector<int> prime;
    int temp=n;
    for(int i=2;i*i<=n;i++){
        if(temp%i==0){
            prime.push_back(i);
            while(temp%i==0){
                temp/=i;
            }
        }
    }
    if(temp>1){
        prime.push_back(temp);
    }
    for(int i = 1;i<=n;i++){
        for(int j :prime){
            if(i+j <= n){
                merg(i,i+j,par,sz);
            }
        }
    }
    set<int> s;
    for(int i = 1;i<=n;i++){
        s.insert(find_set(i,par));
    }
    cout<<s.size();
}
int32_t main(){
    int w;
    cin >> w;
    while(w--){
        solve();
        cout<<"\n";
    }
}