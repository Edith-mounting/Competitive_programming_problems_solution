#include <bits/stdc++.h>
#include <map>
#include <queue>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<int,int> mp;
    mp[0] = 0;
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
    }
    priority_queue<int> pq;
    for(auto i:mp){
        pq.push({i.second});
    }
    int ans = pq.top();
    pq.pop();x
    ans += pq.top();
    cout << ans << "\n";
}
int main()
{
    solve();
}
