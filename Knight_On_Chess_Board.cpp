#include <bits/stdc++.h>
using namespace std;

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
int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = { -1, 1, 1, -1, 2, -2, 2, -2};
int solve(int n, int m, int x, int y, int X, int Y){
    queue<pair< int, int>> q;
    map<pair< int, int>, bool> mp;
    mp[{ x, y}] = true;
    q.push({x, y});
    int ans = 0;
    while(!q.empty()){
        int len = q.size();
        while(len--){
            pair< int, int> temp = q.front();
            q.pop();
            // cout << temp.first << " " << temp.second << "\n";
            if(temp.first == X && temp.second == Y){
                return ans;
            }
            int temp_x, temp_y;
            for(int k = 0; k < 8; k++){
                temp_x = temp.first + dx[k];
                temp_y = temp.second + dy[k];
                if( temp_x<=n && temp_x>=1 && temp_y<=m && temp_y>=1 && !mp[{temp_x, temp_y}]){
                    mp[{temp_x, temp_y}] = true;
                    q.push({temp_x, temp_y});
                }
            }
        }
        ans++;
    }
    return -1;
    
}
int32_t main(){
    int n,m,x,y,X,Y;
    cin >> n >> m >> x >> y >> X >> Y;
    int ans = solve( n, m, x, y, X, Y);
    cout << ans << "\n";
}