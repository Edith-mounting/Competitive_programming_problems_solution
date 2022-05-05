#include <bits/stdc++.h>
using namespace std;
#define int long long
int N = 40000 + 2;
int mod = 1000000007;
vector<int> dp( N, 0);
void solve(){
    int n;
    cin >> n;
    cout << dp[n] << "\n";
}
bool isPalindrome(int k){
    vector<int> temp;
    while(k > 0){
        temp.push_back(k%10);
        k/=10;
    }
    int sz = temp.size();
    for(int i = 0; i < sz/2; i++){
        if(temp[i] != temp[sz - i - 1]){
            return false;
        }
    }
    return true;
}
int32_t main(){
    vector<int> palindrome;
    for(int i = 1; i < N; i++){
        if(isPalindrome(i)){
            palindrome.push_back(i);
        }
    }
    dp[0] = 1;
    int m = palindrome.size();
    for(int i = 0; i < m; i++){
        for(int j = palindrome[i]; j < N; j++){
            dp[j] = (dp[j] + dp[j - palindrome[i]])%mod;
        }
    }

    // cout << palindrome.size() << "\n";
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
