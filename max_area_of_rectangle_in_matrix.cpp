#include <bits/stdc++.h>
using namespace std;

int areaOfHistogram( vector<int> a, int n){
    vector<int> left( n, 0), right( n, 0);
    stack<int> st, st2;
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] >= a[i]){
            st.pop();
        }
        if(st.empty()){
            left[i] = -1;
        }
        else{
            left[i] = st.top();
        }
        st.push(i);
    }
    for(int i = n - 1; i >= 0; i--){
        while(!st2.empty() && a[st2.top()] >= a[i]){
            st2.pop();
        }
        if(st2.empty()){
            right[i] = n;
        }
        else{
            right[i] = st2.top();
        }
        st2.push(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max( ans, (right[i] - left[i] - 1)*a[i]);
    }
    cout << ans << " ";
    return ans;
}
int solve(vector<vector<int>> &a){
    int n = a.size(), m = a[0].size();
    vector< vector<int>> dp( n, vector<int>( m, 0));
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0){
                dp[i][j] = a[i][j];
            }
            else{
                if(a[i][j] == 1)
                    dp[i][j] = dp[i - 1][j] + a[i][j];
            }
        }
        ans = max( ans, areaOfHistogram( dp[i], m));
    }
    return ans;
}
int32_t main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int ans = solve(a);
    cout << ans << "\n";
}