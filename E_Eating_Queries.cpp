#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    cin >> n >> q;
    long long sum = 0;
    long long a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }  
    //sort in reverse order
    sort( a, a + n, greater<long long>());
    for(int i = 1; i < n; i++){
        a[i] += a[i - 1];
    }
    for(int i = 0; i < q; i++){
        long long x;
        cin >> x;
        if( x > sum){
            cout << -1 <<"\n";
            continue;
        }
        if(x == 0){
            cout << 0 << "\n";
            continue;
        }
        cout << lower_bound(a , a + n, x) - a + 1 << "\n";
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--)
        solve();
}