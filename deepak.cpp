#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#define int long long
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    long ans = (long)10000000000;
    vector<long> a1(n,0),a2(m,0);
    for(int i = 0; i < n; i++){
        cin >> a1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> a2[i];
    }
    sort(a2.begin(), a2.end());
    vector<long> sum(m ,(long)0);
    for(int i = m - 2; i >= 0; i--){
        sum[i] = sum[i + 1] + (long)(m - 1 - i)*(a2[i + 1] - a2[i]);
    }
    int l = 0, r = m - 1;
    int mid ;
    while(l <= r){
        mid = (l + r)/2;
        long temp = sum[mid];
        for(int i = 0; i < n; i++){
            if(a1[i] < a2[mid]){
                temp += (a2[mid] - a1[i]);
            }
        }
        if(temp <= ans){
            ans = temp;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
        // if steps is smaller than previous one make l = mid + 1 or make r = mid - 1;
    }
    sort(a1.begin(), a1.end());
    vector<long> sum1(m ,(long)0);
    for(int i = 1; i < n; i++){
        sum1[i] = sum1[i - 1] + (long)(i)*(a1[i] - a1[i - 1]);
    }
    l = 0, r = n - 1;
    while(l <= r){
        mid = (l + r)/2;
        long temp = sum1[mid];
        for(int i = 0; i < m; i++){
            if(a2[i] > a1[mid]){
                temp += (a2[i] - a1[mid]);
            }
        }
        if(temp <= ans){
            ans = temp;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans <<"\n";
}
int32_t main()
{
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}