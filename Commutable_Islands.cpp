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
vector<int> par, sz;
const static bool comp( vector<int> a, vector<int> b){
    return a[2] < b[2];
}
int find_set( int a){
    if( a == par[a]) return a;
    return par[a] = find_set( par[a]);
}
void merge( int a, int b){
    a = find_set( a);
    b = find_set( b);
    if( a == b) return;
    if(sz[a] < sz[b]){
        swap( a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
}
int solve(int n, vector<vector<int>> &b){
    par.resize( n + 1), sz.resize(n + 1);
    for(int i = 1; i <= n; i++){
        par[i] = i;
        sz[i] = 1;
    }
    int ans = 0;
    sort( b.begin(), b.end(), comp);
    for(auto i:b){
        if( find_set( i[0]) != i[1]){
            ans += i[2];
            merge( i[0], i[1]);
        }
    }
    return ans;
    
}
int32_t main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> b(m, vector<int>( 3, 0));
    for(int i = 0; i < m; i++){
        cin >> b[i][0] >> b[i][1] >> b[i][2];
    }
    int ans = solve( n, b);
    cout << ans << "\n";
}