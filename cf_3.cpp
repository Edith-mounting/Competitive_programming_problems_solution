#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i<n ;i++){
        cin >> a[i];
    }
    sort(a , a + n);
    int i;
    for(i = 1;i<n;){
        if(a[i] != a[i-1]){
            break;
        }
        i++;
    }
    if(i == n){
        cout<<-1<<"\n";
        return ;
    }
    int ans = a[i] - a[i-1];
    for(int j = i + 1;j<n;j++){
        ans = __gcd(ans , a[j] - a[i - 1]);
    }
    cout<<ans<<"\n";
}
int main(){
    int t;
    cin>> t;
    while(t--){
        solve();    
    }
}