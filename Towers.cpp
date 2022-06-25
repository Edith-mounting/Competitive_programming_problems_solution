#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> v;
    int x, temp;
    cin >> x;
    v.push_back(x);
    for(int i = 1; i < n; i++){
        cin >> x;
        temp = (upper_bound( v.begin(), v.end(), x) - v.begin());
        if(temp == v.size()){
            v.push_back( x);
        }
        else{
            v[temp] = x;
        }
    }
    cout << v.size() << "\n";
}
int32_t main(){
    solve();
}
