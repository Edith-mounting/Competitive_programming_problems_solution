#include <bits/stdc++.h>
using namespace std;
#define int long long


int solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int ans = 0;
    int i1 = -1;
    for(int i = 0; i < n; i++){
        if(b[i] != 0){
            i1 = i;
        }
    }
    ans = i1 + 1 + n;
    return ans;
}
int32_t main(){
    cout << solve() << "\n";
}
