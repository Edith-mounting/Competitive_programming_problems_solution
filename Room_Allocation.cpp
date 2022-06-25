#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

struct hotel{
    int a, b, i;
};
static bool comp( hotel x, hotel y){
    return x.a <= y.a;
}
void solve(){
    int n;
    cin >> n;
    priority_queue< pair<int,int>, vector< pair<int,int>>, greater< pair<int,int>>> pq;
    vector<hotel> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].a >> v[i].b;
        v[i].i = i;
    }
    vector<int> ans(n);
    sort( v.begin(), v.end(), comp);
    ans[v[0].i] = 1;
    
    int sz = 1;
    pq.push({v[0].b, sz});
    for(int i = 1; i < n; i++){
        pair<int, int> x = pq.top();
        // cout << x.second << " " << x.first <<"\n";
        if(x.first < v[i].a){
            pq.pop();
            ans[v[i].i] = x.second;
            pq.push({ v[i].b, x.second});
        }
        else{
            sz++;
            ans[v[i].i] = sz;
            pq.push({v[i].b, sz});
        }
    }
    cout << sz << "\n";
    for(int i:ans){
        cout << i << " ";
    }
}
int32_t main(){
    solve();
}
