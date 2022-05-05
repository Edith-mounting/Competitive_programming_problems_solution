#include <bits/stdc++.h>
using namespace std;
#define int long long

bool solve(){
    string s;
    cin >> s;
    int x = 1;
    int n = s.length();
    for(int i = 1; i < n; i++){
        if(s[i] == s[i - 1]){
            x++;
        }
        else{
            if(x == 1){
                return false;
            }
            x = 1;
        }
    }
    if(x == 1){
        return false;
    }
    return true;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        if(solve()){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
