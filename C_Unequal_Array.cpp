#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    int i1 = -1, i2 = -1;
    for(int i = 0; i < n - 1; i++){
        if(a[i] == a[i + 1]){
            i1 = i;
            break;
        }
    }
    for(int i = n - 1; i >= 1; i--){
        if(a[i - 1] == a[i]){
            i2 = i;
            break;
        }
    }
    if(i1 == -1){
        ans = 0;
    }
    else{
        int len = (i2 - i1 + 1);
        if(len <= 3){
            ans = (len - 2);
        }
        else{
            ans = (len - 3);
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
