#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += (s[i] - 'a' + 1);
    }
    if(n%2 == 1){
        ans -= 2*min(s[0] - 'a' + 1, s[n - 1] - 'a' + 1);
    }
    if(ans < 0){
        cout << "Bob" << " "<< abs(ans);
    }
    else cout << "Alice "<< ans;
    cout << "\n";
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
