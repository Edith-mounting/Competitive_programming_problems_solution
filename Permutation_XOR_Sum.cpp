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
    int n;
    cin >> n;
    if(n%2 == 1){
        n--;
    }
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}