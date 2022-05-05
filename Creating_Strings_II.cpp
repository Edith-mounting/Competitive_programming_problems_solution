#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int powd( int x, int y){
    if(y == 0){
        return 1;
    }
    else if(y%2 == 0){
        int t = powd( x, y/2);
        return (t*t)%mod;
    }
    else{
        int t = powd( x, y/2);
        return (((t*t)%mod)*x)%mod;
    }
}
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> fact( n + 1, 1);
    for(int i = 2; i <= n; i++){
        fact[i] = (fact[i - 1] * i)%mod;
    }
    int a[26] = {};
    for(int i = 0; i < n; i++){
        a[s[i] - 'a']++;
    }
    int ans = fact[n];
    for(int i = 0; i < 26; i++){
        if(a[i] > 1){
            ans = (ans * powd( fact[a[i]], mod - 2))%mod;
        }
    }
    cout << ans << "\n";
}
int32_t main(){
    solve();
}
