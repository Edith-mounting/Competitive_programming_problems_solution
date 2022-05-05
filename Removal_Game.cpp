    #include <bits/stdc++.h>
    using namespace std;
    #define int long long

    int mod = 1000000007;

    int f(vector<vector<int>> &dp, int l, int r, int &turn, vector<int> &a){
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        if(l == r){
            return dp[l][r] = a[l];
        }
        return dp[l][r] = max(a[l] - f(dp, l + 1, r, turn, a) ,a[r] - f(dp, l, r - 1, turn, a));
    }
    void solve(){
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        vector<vector<int>> dp(n , vector<int>(n, -1));
        int turn  = 1;
        int ans = 0;
        int dif =  f(dp, 0, n - 1, turn, a);
        ans = (dif + sum)/2;
        cout << ans << "\n";
    }
    int32_t main(){
        solve();
    }
