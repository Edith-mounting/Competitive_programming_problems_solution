#include <bits/stdc++.h>

using namespace std;
#define int long long

bool isPossible(vector<int> a, int n, int mid, int maxi){
    int x1 = mid/2, x2 = mid/2;
    if(mid%2 == 1){
        x1++;
    }
    for(int i = 0; i < n; i++){
        int temp = (maxi - a[i]);
        int k1 = temp/2;
        if(k1 <= x2){
            x2 -= k1;
            if(temp%2 == 1){
                x1--;
            }
        }
        else{
            temp = temp - x2*2;
            x2 = 0;
            if(temp > x1){
                return false;
            }
            x1 -= temp;  
        }
        a[i] = 0;
    }
    if(x1 < 0 || x2 < 0){
        return false;
    }
    return true;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int low = 0, high = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        high += a[i];
    }
    high = 1000000000000000000;
    sort( a.begin(), a.end());
    int mid, ans = high;
    while(low <= high){
        mid = (low + high)/2;
        if(isPossible( a, n, mid, a[n - 1])){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    low = 1;
    high = ans;
    while(low <= high){
        mid = (low + high)/2;
        if(isPossible( a, n, mid, a[n - 1] + 1)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        } 
    }
    cout << ans << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    
}