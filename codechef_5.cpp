#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int sum = 0;
    int temp;
    for(int i = 0; i < n; i++){
        if( i == 0){
            temp = abs(b[i] - a[i + 1]) + abs(a[i] - b[i + 1]);
            sum = abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]);
        }
        else if(i == n - 1){
            temp = abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1]);
            sum = abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
        }
        else{
            temp = abs(b[i] - a[i + 1]) + abs(a[i] - b[i + 1]) + abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1]);
            sum = abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]) + abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
        }
        if(sum >= temp){
            cout << i << ' ';
            swap(a[i], b[i]);
        }
        for(int i = 1; i < n; i++){
            sum += abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
        }
    }
    cout << sum << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }    
}