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
int solve(vector<string> &a, string s){
    int n = a.size(), m = a[0].size();
    int len = s.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == s[0]){
                if(len == 1){
                    return 1;
                }
                // cout << i << " " << j << "\n";
                int cur = 1;
                queue< pair< int, int>> q;
                q.push({ i, j});
                while(!q.empty() && cur < len){
                    int len = q.size();
                    while(len--){
                        pair< int, int> temp = q.front();
                        q.pop();
                        int temp_x, temp_y;
                        for(int k = 0; k < 4; k++){
                            temp_x = temp.first + dx[k];
                            temp_y = temp.second + dy[k];
                            if(isValid( temp_x, temp_y, n, m) && a[temp_x][temp_y] == s[cur]){
                                // cout << cur <<  " ";
                                q.push({ temp_x, temp_y});
                            }
                        }
                    }
                    // cout << "\n";
                    if(q.size() > 0)
                        cur++;
                }
                if(cur == len){
                    // cout << cur << " ";
                    return 1;
                }
            }
        }
    }
    return 0;
}
int32_t main(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    string s;
    cin >> s;
    int ans = solve( a, s);
    cout << ans << "\n";
}