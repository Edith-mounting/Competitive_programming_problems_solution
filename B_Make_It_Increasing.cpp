#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        int c = 0;
        reverse(v.begin(),v.end());
        for(int i = 0; i < n - 1; i++){
            if(v[i] == 0){
                c = -1;
                break;
            }
            while( v[i] <= v[i + 1] ){
                v[i + 1]/=2;
                c++;
            }
        }
        cout <<c <<endl;
    }
    return 0;
}