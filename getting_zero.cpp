#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    int k = 32768;
    int x;
    for(int lm = 0; lm < n; lm++){
        cin >> x;
        int count = 0;
        queue<int> q;
        vector<bool> vis(k + 1, false);
        q.push(x);
        vis[x] = true;
        while(!q.empty() && !vis[0]){
            int len = q.size();
            while(len--){
                int temp = q.front();
                q.pop();
                if(temp == 0){
                    break;
                }
                int temp1 = (temp + 1)%k;
                if(!vis[temp1]){
                    vis[temp1] = true;
                    q.push(temp1);
                }
                temp1 = (temp*2)%k;
                if(!vis[temp1]){
                    vis[temp1] = true;
                    q.push(temp1);
                }
            }
            count++;
        }
        cout << count << " ";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }    
}