#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int > > > adj(n);
    int u , v , w;
    for(int i = 0; i<m ; i++){
        cin >> u >> v;
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
    int src,dest;
    cin>> src>> dest;
    vector<int > dis(n,inf);
    vector<bool> vis(n,false);
    priority_queue<pair<int,int > ,vector<pii>,greater<pii>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        pair<int,int > temp = pq.top();
        pq.pop();
        if(!vis[temp.second]){
            vis[temp.second] = true;
            dis[temp.second] = temp.first;
        }
        for(pair<int,int> j:adj[temp.second]){
            if(!vis[j.first]){
                int temp_dist = dis[temp.second] + j.second;
                if(temp_dist < dis[j.first]){
                    dis[j.first] = temp_dist;
                    pq.push({temp_dist , j.first});
                }
            }   
        }
    }
    for(int i = 0;i<n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";
    // cout<<dis[dest]<<"\n"; 
}
int32_t main(){
    FIO;
    solve();
}