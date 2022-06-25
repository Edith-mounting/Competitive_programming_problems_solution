#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vector< int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 1;
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(2*a[i] > a[i - 1]){
            l++;
        }
        else{
            if(l >= k + 1){
                ans += (l - k);
            }
            l = 1;
        }
    }
    if(l >= k + 1){
        ans += (l - k);
    }
    cout << ans << "\n";
}

int32_t main(){
    int w;
    cin >> w;
    while (w--)
    {
        /* code */
        solve();
    }
}