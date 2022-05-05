#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define int long long
#define mod 1000000007

void solve(){
	int n;
    cin >> n;
    int k1;
    priority_queue<int> pq1, pq2;
    for(int i = 0; i < n; i++){
        cin >> k1;
        pq2.push(k1);
    }
    vector<int> prefix(n + 1, 0);
    int q;
    cin >> q;
    int a, b, x;
    for(int i = 0; i < q; i++){
        cin >> a >> b >> x;
        a--, b--;
        prefix[a] += x;
        prefix[b + 1] -= x;
    }
    vector<int> val( n, 0);
    val[0] = prefix[0];
    pq1.push(prefix[0]);
    for(int i = 1; i < n; i++){
        val[i] = val[i - 1] + prefix[i];
        pq1.push(val[i]);
    }
    int ans = 0;
    while(!pq1.empty() && !pq2.empty()){
        if(pq1.top() >= pq2.top()){
            ans++;
            pq1.pop();
        }
        pq2.pop();
    }
    cout << ans <<"\n";
}
// main function
int32_t main()
{
	solve();
}
