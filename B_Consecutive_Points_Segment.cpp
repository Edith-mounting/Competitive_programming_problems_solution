#include <bits/stdc++.h>
using namespace std;
#define int long long

bool solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int count2 = 0, count3 = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1] + 1){
            continue;
        }
        if(a[i] == a[i - 1] + 2){
            if(count2 == 0 && count3 == 0){
                count2++;
                continue;
            }
            if(count2 == 1 && count3 == 1){
                return false;
            }
            if(count2 <= 1){
                count2++;
                a[i]--;
            }
            else{
                return false;
            }
        }
        else if(a[i] == a[i - 1] + 3){
            if(count2 == 0 && count3 == 0){
                a[i]--;
                count3++;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
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
