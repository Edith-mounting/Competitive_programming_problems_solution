#include <bits/stdc++.h>
using namespace std;
#define int long long


int solve(int n,string s, int B, int G){
    int tmp = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            tmp++;
        }
        else{
            if(tmp > 0){
                int k1, k2;
                if(tmp%2 == 1){
                    k1 = tmp/2 + 1;
                }
                else{
                    k1 = tmp/2;
                }
                k2 = tmp/2;
                if(B > G){
                    ans += min(B, k1);
                    ans += min(G, k2);
                    B -= min(B, k1);
                    G -= min(G, k2);
                }
                else{
                    ans += min(G, k1);
                    ans += min(B, k2);
                    G -= min(G, k1);
                    B -= min(B, k2);
                }
                if(B==0 && G==0){
                    tmp = 0;
                    break;
                }
            }
            tmp = 0;
        }
    }
    if(tmp > 0){
        int k1, k2;
        if(tmp%2 == 1){
            k1 = tmp/2 + 1;
        }
        else{
            k1 = tmp/2;
        }
        k2 = tmp/2;
        if(B > G){
            ans += min(B, k1);
            ans += min(G, k2);
            B -= min(B, k1);
            G -= min(G, k2);
        }
        else{
            ans += min(G, k1);
            ans += min(B, k2);
            G -= min(G, k1);
            B -= min(B, k2);
        }
    }
    return ans;
}
int32_t main(){
    int n, B, G;
    string s;
    cin >> n >> s >> B >> G;
    cout << solve( n, s, B, G) << "\n";
}
