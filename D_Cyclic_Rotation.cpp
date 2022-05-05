#include <bits/stdc++.h>
using namespace std;
#define int long long

void update(vector<int> &a, int n){
    map<int, pair<int , int>> mp;
    for(int i = 0; i < n; i++){
        if(mp.find(a[i]) != mp.end()){
            pair<int, int> tmp = mp[a[i]];
            mp[a[i]] = {i, tmp.second + 1};
        }
        else{
            mp[a[i]] = {i, 1};
        }
    }
    int j = 0;
    pair<int, int> tmp;
    for(int i = 0; i < n; i++){
        tmp = mp[a[i]];
        if(tmp.first == i){
            while(tmp.second--){
                a[j++] = a[i]; 
            }
        }
    }
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    update(a, n);
    update(b, n);
    if(a == b){
        cout << "YES\n";
    }
    else cout << "NO\n";
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
