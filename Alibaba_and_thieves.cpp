#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#define int long long
#define mod   998244353
using namespace std;

bool comp(pair<int, int> a, pair<int,int> b){
    return a.first < b.first;
}
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());
    int count = 0;
    int start = 0;
    for(auto i: v){
        if(i.second<=start && start<=i.first){
            count++;
            start++;
        }else if(start<i.second){
            start = i.second+1;
            count++;
        }
    }
    cout << count << '\n';
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}