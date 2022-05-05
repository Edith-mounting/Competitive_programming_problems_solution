#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    vector<int> sum(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    sum[0] = a[0];
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    int j = 0, k = 0;
    for(int i = n; i >= 1; i--){
        sum[i] = sum[i] + j*i;
        k = ((x - sum[i])/i) + 1;
        if(k > 0){
            ans += k*i;
            j += k;
        }
    }
    cout << ans << "\n";
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
