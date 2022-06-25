#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a,b;
    cin >> a >> b;
    if(a%2 == 0){
        cout << "YES";
        return;
    }
    if(b%2 == 1){
        cout << "YES";
        return ;
    }
    cout << "NO";
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << "\n";
    }
}