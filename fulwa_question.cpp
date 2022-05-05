#include<iostream>
#include <vector>
#include <set>
using namespace std;

#define mod 1000000007
int32_t main(){
    int n , q;
    cin >> n>> q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[q];
    for(int i = 0; i < q; i++){
        cin >> b[i];
    }
    vector<int> v1(q), v2(q);
    for(int i = 0; i < q; i++){
        cin >> v1[i];
    }
    for(int i = 0; i < q; i++){
        cin >> v2[i];
    }
    for(int i = 0; i < q; i++){
        if(b[i] == 1){
            a[v1[i] - 1] = v2[i];
        }
        else{
            int ans = 0;
            int p = 2;
            for(int j = v1[i] - 1; j < v2[i];j++){
                ans = (ans + (((p%mod) + j - v1[i] + 2)%mod * a[j])%mod)%mod;
                p = p*2;
                p%=mod;
            }
            cout<<ans<<"\n";
        }
    }
}