#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using namespace std;


void solve(){
    int n ;
    cin>>n;
    string s;
    cin>>s;
    int ans =0;
    for(int i=0;i<n;i++){
        vector<int> left(26,0),right(26,0);
        for(int j = i;j<n;j++){
            right[s[j]-'a']++;
        }
        for(int j = 0;j<i;j++){
            left[s[j]-'a']++;
        }
        int c1 =0;
        for(int j = 0;j<26;j++){
            if(left[j]>0 && right[j]>0){
                c1++;
            }
        }
        ans = max(c1,ans);
    }
    cout<<ans;
}
int32_t main(){
    int w=1;
    //cin >> w;
    while(w--){
        solve();
        cout<<"\n";
    }
}