#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
vector<string> a;
string s,e;
int n;

void bfs(){
    map<string,bool> mp;
    map<string,string> m;
    queue<string> q;
    q.push(s);
    mp[s]=true;
    while(!q.empty()){
        string k=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(mp.find(a[i])==mp.end()){
                int count=0;
                for(int j=0;j<k.length();j++){
                    if(k[j]!=a[i][j]){
                        count++;
                    }
                }
                if(count==1){
                    m[a[i]]=k;
                    q.push(a[i]);
                    mp[a[i]]=true;
                }
            }
        }   
    }
    vector<string> ans;
    ans.pb(e);
    while(m[e]!=s){
        ans.pb(m[e]);
        e=m[e];
    }
    ans.pb(s);
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int32_t main(){
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>s>>e;
    bfs();
}