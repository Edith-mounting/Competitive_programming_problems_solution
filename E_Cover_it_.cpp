#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
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
#define vip             vector<pair<int,double>>
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
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
 
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)*x);
    }
}
int n;
vector<bool> vis;
vi level;
vi ans1,ans2;
vector<vi> adj;
void bfs(int i){
    vis[i]=true;
    level[i]=0;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int child=q.front();
        q.pop();
        if(level[child]%2==0){
            ans1.pb(child);
        }
        else{
            ans2.pb(child);
        }
        for(int j:adj[child]){
            if(!vis[j]){
                q.push(j);
                vis[j]=true;
                level[j]=level[child]+1;
            }
        }
    }
}
int32_t main()
{
	FIO;
    int w;
    cin>>w;
    while(w--){
        int m;
        cin>>n>>m;
        vis.clear();
        level.clear();
        adj.clear();
        ans1.clear();
        ans2.clear();
        vis.resize(n+1,false);
        level.resize(n+1,0);
        adj.resize(n+1);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                bfs(i);
            }
        }
        // cout<<ans.size()<<"\n";
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<"\n";
        if(ans1.size()<ans2.size()){
            cout<<ans1.size()<<"\n";
            for(int i:ans1){
                cout<<i<<" ";
            }
        }
        else{
            cout<<ans2.size()<<"\n";
            for(int i:ans2){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }
}