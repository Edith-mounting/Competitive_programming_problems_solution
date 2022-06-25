#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};
bool isValid( int i, int j, int n, int m){
    if(i>=n || i < 0 || j >= m || j < 0){
        return false;
    }
    return true;
}
void dfs(int i, int j, vector<vector<bool>> &blue,int n,int m, vector<vector<int> > &a){
    blue[i][j] = true;
    int temp_x, temp_y;
    for(int k = 0; k < 4; k++){
        temp_x = i + dx[k];
        temp_y = j + dy[k];
        if(isValid( temp_x, temp_y, n, m) && a[temp_x][temp_y] >= a[i][j] && !blue[temp_x][temp_y]){
            dfs( temp_x, temp_y, blue, n, m, a);
        }
    }
}

int solve(vector<vector<int>> &a){
    int n = a.size(), m = a[0].size();
    vector<vector<bool>> blue( n, vector<bool>( m, false));
    for(int i = 0; i < n; i++){
        dfs( i, 0, blue, n, m, a);
    }
    for(int j = 0; j < m; j++){
        dfs( 0, j, blue, n, m, a);
    }
    // for(auto i:blue){
    //     for(int j:i){
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    vector<vector<bool>> red( n, vector<bool>( m, false));
    for(int i = 0; i < n; i++){
        dfs( i, m - 1, red, n, m, a);
    }
    for(int j = 0; j < m; j++){
        dfs( n - 1, j, red, n, m, a);
    }
    for(auto i:red){
        for(int j:i){
            cout << j << " ";
        }
        cout << "\n";
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if( blue[i][j] && red[i][j]){
                ans++;
            }
        }
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