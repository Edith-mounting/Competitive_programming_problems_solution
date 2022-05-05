#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int ans = 10000000;
    for(int i = 0; i < n - 1; i++){
        int x1 = max(v[i], v[i + 1]);
        int x2 = min(v[i], v[i + 1]);
        if(x1 > x2*2){
            ans = min((x1 + 1)/2 , ans);
        }
        else{
            int x = (x1 - x2);
            x1 -= 2*x;
            x2 -= x;
            if((x1 + x2)%3 == 0){
                ans = min( (x1 + x2)/3 + x, ans);
            }
            else{
                ans = min( (x1 + x2)/3 + x + 1, ans);
            }
        }
    }
    for(int i = 1; i < n - 1; i++){
        if(v[i - 1]%2 == 1 && v[i + 1]%2 == 1){
            ans = min(ans, (v[i - 1] + v[i + 1])/2);
        }
    }
    sort(v.begin(), v.end());
    ans = min((v[0] + 1)/2 + (v[1] + 1)/2, ans);
    cout << ans << "\n";
}
int32_t main(){
    solve();
}
