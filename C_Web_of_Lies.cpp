#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
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

int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        return powd(x,y/2)*powd(x,y/2);
    }
    else{
        int t=powd(x,y/2);
        return (x*t*t);
    }
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    int count=n;
    vector<int> vis(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(u<v){
            if(vis[u]==0){
                count--;
            }
            vis[u]++;
        }
        else{
            if(vis[v]==0){    
                count--;
            }
            vis[v]++;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int k1;
        cin>>k1;
        if(k1==1){
            int x,y;
            cin>>x>>y;
            if(x<y){
                if(vis[x]==0){
                    count--;
                }
                vis[x]++;
            }
            else{
                if(vis[y]==0){    
                    count--;
                }
                vis[y]++;
            }
        }
        else if(k1==2){
            int x,y;
            cin>>x>>y;
            if(x<y){
                if(vis[x]==1){
                    count++;
                }
                vis[x]--;
            }
            else{
                if(vis[y]==1){    
                    count++;
                }
                vis[y]--;
            }
        }
        else{
            cout<<count<<'\n';
        }
    }
}