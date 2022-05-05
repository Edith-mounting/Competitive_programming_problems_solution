#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

void solve(){
    int n;
    cin >> n;
    vector<pair< int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort( a.begin(), a.end());
    int ans = 0;
    int curr = 0;
    for(int i = 0; i < n; i++){
        curr = curr + a[i].first;
        ans += ( a[i].second - curr); 
    }
    cout << ans << "\n";
}
int32_t main(){
    solve();
}
