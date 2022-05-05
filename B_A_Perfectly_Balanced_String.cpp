#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    string s;
    cin >> s;
    int n = s.length();
    map<char,int> mp;
    bool bl = true;
    for(int i = 1; i < n; i++){
        if(s[i] == s[0]){
            int len = i;
            for(int j = i; j < n; j++){
                if(s[j - len] != s[j]){
                    bl = false;
                    break;
                }
            }
            break;
        }
        else if(mp.find(s[i]) != mp.end()){
            bl = false;
            break;
        }
        mp[s[i]] = true;
    }
    if(bl){
        cout << "YES\n";
    }
    else cout << "NO\n";
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
