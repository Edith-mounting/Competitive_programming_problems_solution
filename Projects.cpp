#include <bits/stdc++.h>
using namespace std;
#define int long long

struct job{
    int start, end, profit;
};
static bool comp(job a, job b){
    return a.end < b.end;
}
void solve(){
    int n;
    cin >> n;
    vector<job> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].start >> v[i].end >> v[i].profit;
    }
    sort(v.begin(), v.end(), comp);
    vector<int> dp(n, 0);
    dp[0] = v[0].profit;
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1], v[i].profit);
        int l = 0, r = i - 1;
        int mid;
        while(l <= r){
            mid = (l + r)/2;
            if(v[mid].end < v[i].start){
                dp[i] = max( dp[i], dp[mid] + v[i].profit);
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }
    cout << dp[n - 1] << "\n";
}
int32_t main(){
    solve();
}
