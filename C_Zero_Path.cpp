#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector< vector<int>> a( n, vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    if( (n + m)%2 == 0){
        cout << "NO";
        return;
    }
    
    vector< vector<int>> v1( n, vector<int>(m,0));
    vector< vector<int>> v2( n, vector<int>(m,0));
    v1[0][0] = a[0][0], v2[0][0] = a[0][0];
    for(int i = 1; i < n; i++){
        v1[i][0] = v1[i - 1][0] + a[i][0];
        v2[i][0] = v2[i - 1][0] + a[i][0];
    }
    for(int j = 1; j < m; j++){
        v1[0][j] = v1[0][j - 1] + a[0][j];
        v2[0][j] = v2[0][j - 1] + a[0][j];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            v1[i][j] = a[i][j] + max( v1[i-1][j], v1[i][j-1]);
            v2[i][j] = a[i][j] + min( v2[i-1][j], v2[i][j-1]);
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << v1[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << v2[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    if(v1[n-1][m-1] >= 0 && v2[n-1][m-1] <= 0){
        cout << "YES";
        return;
    }
    cout << "NO";
    return;
}
int32_t main(){
    int w;
    cin >> w;
    while(w--){
        solve();
        cout << "\n";
    }
}