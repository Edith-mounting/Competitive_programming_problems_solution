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
int solve(vector<vector<int>> A, vector<vector<int>> B){
    map<int , int> ladder, snake;
    for(auto i:A){
        ladder[i[0]] = i[1];
    }
    for(auto i:B){
        snake[i[0]] = i[1];
    }
    int init = 1;
    queue< int> q;
    q.push( init);
    int ans = 0;
    map< int, bool> vis;
    while( !q.empty()){
        int len = q.size();
        while(len--){
            int temp = q.front();
            q.pop();
            cout << temp << " ";
            if( temp == 100){
                return ans;
            }
            for(int i = 1; i <= 6; i++){
                if( i + temp <= 100 && vis.find( i + temp)==vis.end()){
                    vis[i + temp] = true;
                    if( ladder.find( i + temp) != ladder.end()){
                        q.push( ladder[i + temp]);
                        vis[ladder[i + temp]] = true;
                    }
                    else if( snake.find( i + temp) != snake.end()){
                        q.push( snake[ i + temp]);
                        vis[snake[i + temp]] = true;
                    }
                    else q.push( i + temp);
                }
            }
        }
        ans++;
    }
    return -1;
}
int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(2,0)), b( m, vector<int>(2,0));
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i][0] >> b[i][1];
    }
    int ans = solve( a, b);
    cout << ans << "\n";
}