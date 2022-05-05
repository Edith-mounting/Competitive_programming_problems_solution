#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool isPossible(vector<int> a, int mid, int k){
    int temp = 0;
    for(int i = mid; i >= 0; i--){
        a[i] =(a[i] + temp)%10;
        if(a[i] != 0){
            temp += (10 - a[i]);
        }
    }
    if(temp <= k){
        return true;
    }
    return false;
}
void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
        a[i] = s[i] - '0';
    }
    int ans = 0;
    int l = 0, r = n - 1;
    int mid;
    while(l <= r){
        mid = (l + r)/2;
        if(isPossible(a , mid , k)){
            ans = mid + 1;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}