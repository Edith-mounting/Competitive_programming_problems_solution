#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1000000007;

int powd(int x, int y){
    if(y == 0){
        return 1;
    }
    else if(y%2 == 0){
        int t = powd(x, y/2);
        return (t*t)%mod;
    }
    else{
        int t = powd(x, y/2);
        return (((t*t)%mod)*x)%mod;
    }
}
void solve(){
    int n;
    cin >> n;
    int k = n*n;
    if(n == 1){
        cout << 2 << "\n";
        return ;
    }
    if(n%2 == 0){
        int ans = powd( 2, k - 2);
        ans = (ans + powd(2, (k/4) - 1))%mod;
        ans = (ans + powd(2, k/2 - 2))%mod;
        cout << ans << "\n";
    }
    else{
        int ans = powd( 2, k - 2);
        ans = (ans + powd( 2, (k - 1)/4))%mod;
        ans = (ans + powd( 2, (k - 3)/2))%mod;
        cout << ans << "\n";
    }
}
int32_t main(){
    solve();
}
