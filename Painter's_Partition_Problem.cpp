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

bool isValid(int a, int b, vector<int> &c, ll mid){
    ll x = 1, cur = 0;
    int n = c.size();
    for(int i = 0; i < n; i++){
        if( cur + (ll)b*c[i] <= mid){
            cur += (ll)b*c[i];
        }
        else{
            if((ll)b*c[i] > mid){
                return false;
            }
            x++;
            cur = (ll)b*c[i];
        }
        // cout << cur << " " ;
    }
    // cout << x << " " << mid << "\n";
    return (int)x<=a;
}
int solve(int a, int b, vector<int> &c){
    ll low = 1, high = 10000000000000;
    ll mid, ans = high;
    while( low <= high){
        mid = low + ( high - low)/2;
        if( isValid( a, b, c, mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    ans = ans%10000003;
    return (int)ans;
}
int32_t main(){
    int a, b, n;
    cin >> a >> b >> n;
    vector<int> v(n);
    for(int i= 0; i < n; i++){
        cin >> v[i];
    }
    cout << solve( a, b, v);
}