#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vi> adj(n+1);
    int u,v;
    vector<int> inorder(n+1,0);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].pb(v);
        inorder[v]++;
    }
    queue<pii> q;
    for(int i=1;i<n+1;i++){
        if(inorder[i]==0){
            q.push({i,0});
        }
    }
    //vector<bool> vis(n+1,false);
    vector<int> ans(n+1);
    while(!q.empty()){
        pii temp=q.front();
        q.pop();
        ans[temp.ff]=temp.ss;
        for(int i:adj[temp.ff]){
            inorder[i]--;
            if(inorder[i]==0){
                q.push({i,temp.ss+1});
            }
        }
    }
    for(int i=1;i<n+1;i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<"\n";
}
int32_t main(){
    FIO;
    int w=1;
    //cin>>w;
    while(w--){
        solve();
    }    
}
