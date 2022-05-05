#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve(){
    int n,l,r,p;
    cin>>n;    
    vector<vector<int>> v(n,vector<int>(3));
    int s=0;
    for(int k = 0;k<n;){
        cin>>l>>r>>p;
        v[k] = {l,r,p};
        int flag=0;
        for(int i=0;i<k;i++){
            // cout<<'*'<<v[i][0]<<v[i][1]<<endl;
            if(l<=v[i][0] && r>=v[i][1]){
             flag=1;
             break;
            }
        }
        if(flag==0)
        s+=p;
        
        cout<<s<<'\n';
        k++;
    }
    
}

int32_t main(){
    int w;
    cin >> w;
    while(w--){
        solve();
    }
}