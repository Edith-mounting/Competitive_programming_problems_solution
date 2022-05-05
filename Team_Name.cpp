#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define int             long long
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        map<string,bool> mp;
        string a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]=true;
        }
        vector<vector<string>> v(26);
        for(int i=0;i<n;i++){
            v[a[i][0]-'a'].pb(a[i]);
        }
        int ans=0;
        string x="",y="";
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                int c1=0,c2=0;
                for(int k=0;k<v[i].size();k++){
                    x=(char)('a'+j);
                    for(int p=1;p<v[i][k].length();p++){
                        x+=v[i][k][p];
                    }
                    if(mp.find(x)==mp.end()){
                        c1++;
                    }
                }
                for(int k=0;k<v[j].size();k++){
                    x=(char)('a'+i);
                    for(int p=1;p<v[j][k].length();p++){
                        x+=v[j][k][p];
                    }
                    if(mp.find(x)==mp.end()){
                        c2++;
                    }
                }
                ans+=2*c1*c2;
            }
        }
        cout<<ans<<"\n";
    }
}