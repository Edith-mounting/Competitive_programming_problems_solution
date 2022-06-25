#include <bits/stdc++.h>
using namespace std;

int binary_search( int x){
    long long low = 1, high = x;
    long long ans = 1;
    long long mid;
    while( low <= high){
        mid = low + (long long)(high - low)/2;
        if( (long long)mid*mid == (long long)x){
            return (int)mid;
        }
        else if(mid*mid < (long long)x){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return (int)ans;
}
#define ll long long

int solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> b(k);
    for(int i = 0; i < k; i++){
        cin >> b[i];
    }
    map< int, int> mp1, mp2;
    for(int i:a){
        mp1[i]++;
    }
    vector<>
    for()
}
int32_t main(){
    int w;
    cin >> w;
    while( w--){
        solve();
    }
}