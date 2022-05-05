#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

bool isPossible(vector<int> &k, int n, int mid, int t){
    int temp = 0;
    for(int i = 0; i < n; i++){
        temp += mid/k[i];
        if(temp >= t){
            return true;
        }
    }
    return false;
}
void solve(){
    int n, t;
    cin >> n >> t;
    vector<int> k(n);
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    int l = 0, r = 1000000000000000000;
    int ans = 0, mid;
    while( l <= r){
        mid = (l + r)/2;
        if(isPossible( k, n, mid, t)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << "\n";
}
int32_t main(){
    solve();
}
