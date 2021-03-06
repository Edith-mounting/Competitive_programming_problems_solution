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
int solve(int a){
    if( a <= 1) return a;
    int ans = binary_search( a);
    return ans;
}
int32_t main(){
    int a;
    cin >> a;
    cout << solve( a);
}