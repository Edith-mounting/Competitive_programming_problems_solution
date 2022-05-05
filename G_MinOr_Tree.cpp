#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
#include <map>
#include <algorithm>
#include <string.h>
#define int long long
#define mod 1000000007
using namespace std;

int power(int a, int b){
    if(b==0){
        return 1;
    }
    int res = 1;
    while(b>0){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b = b/2;
    }
    return res;
}

int gcd(int a,int b){
    if(a==0 || b==0){
        return a+b;
    }

    return gcd(b, a%b);
}

struct edge{
    int u, v, w;
};

bool checkconnected(vector<edge>& v, int n){
    vector<int> edges[n+1];
    if((int)v.size()<(n-1)) return false;
    for(auto i: v){
        edges[i.u].push_back(i.v);
        edges[i.v].push_back(i.u);
    }
    queue<int> q;
    vector<bool> visited(n+1, false);
    int count = 1;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int tmpx = q.front(); q.pop();
        for(auto child: edges[tmpx]){
            if(!visited[child]){
                visited[child] = true;
                count++;
                q.push(child);
            }
        }
    }
    return count==n;
}


void solve(){
    int n, m;
    cin >> n >> m;
    vector<edge> v(m);
    for(int i=0; i<m; i++){
        cin >> v[i].u >> v[i].v >> v[i].w;
    }
    int k = 29;
    int ans = 0;
    while(k>=0){
        vector<edge> nk;
        int p = 1<<k;
        for(auto i: v){
            if((i.w&p)==0){
                nk.push_back(i);
            }
        }
        if(checkconnected(nk, n)){
            v.clear();
            v = nk;
        }else{
            ans = ans | p;
        }
        k--;
    }
    cout << ans << '\n';


}


int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}