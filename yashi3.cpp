#include <bits/stdc++.h>

using namespace std;
#define int long long

int powd(int x, int y){
    if(y == 0){
        return 1;
    }
    else if(y%2 == 0){
        int t = powd(x, y/2);
        return (t*t);
    }
    else{
        int t = powd(x, y/2);
        return (t*t*x);
    }
}
void solve(){
    int x,c;
    cin >> x >> c;
    map<int,int> mp;
    int temp = x;
    int b = 1;
    for(int i = 2; i*i <= x; i++){
        while(temp%i == 0){
            mp[i]++;
            if(mp[i] >= c){
                b = b*i;
                mp[i] -= c;
            }
            temp/=i;
        }
    }
    if(temp > 1){
        mp[temp]++;
        if(mp[temp] >= c){
            b = b*temp;
            mp[temp] -= c;
        }
    }
    int ans = 1;
    for(auto i:mp){
        ans = ans*powd( i.first, i.second);
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