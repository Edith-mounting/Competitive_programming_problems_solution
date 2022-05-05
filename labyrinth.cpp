#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

#define ff              first
#define ss              second
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
vector<vector<int>> adj;
int n,m;
vector<int> par;
vector<bool> vis;
void bfs(int start,int end){
    queue<int> q;
    q.push(start);
    for(int i=0;i<n*m;i++){
        vis[i]=false;
    }
    vis[start]=true;
    par[start]=-1;
    bool b=false;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int nb:adj[cur]){
            if(!vis[nb]){
                q.push(nb);
                par[nb]=cur;
                vis[nb]=true;
            }
        }
    }
    //for(int i=0;i<n*m;i++){
      //  cout<<par[i]<<" ";
    //}
    string s="";
    int i=end;
    while(par[i]!=-1){
        int k=par[i];
        if(k==i+1){
            s+='L';
        }
        else if(k==i+m){
            s+='U';
        }
        else if(k==i-1){
            s+='R';
        }
        else{
            s+='D';
        }
        i=k;
    }
    if(i==start){
        cout<<"YES"<<"\n";
        cout<<s.length()<<"\n";    
        reverse(s.begin(),s.end());
        cout<<s<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}
int32_t main(){
    int start,end;
    cin>>n>>m;
    char a[n][m];
    par.resize(n*m,-1);
    vis.resize(n*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    adj.resize(n*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!='#'){
                if(a[i][j]=='A'){
                    start=m*i+j;
                }
                if(a[i][j]=='B'){
                    end=m*i+j;
                }
                if(i+1<n){
                    if(a[i+1][j]!='#'){
                        adj[m*i+j].pb(m*(i+1)+j);
                    }
                }
                if(i-1>=0){
                    if(a[i-1][j]!='#'){
                        adj[m*i+j].pb(m*(i-1)+j);
                    }
                }
                if(j+1<m){
                    if(a[i][j+1]!='#'){
                        adj[m*i+j].pb(m*(i)+j+1);
                    }
                }
                if(j-1>=0){
                    if(a[i][j-1]!='#'){
                        adj[m*i+j].pb(m*(i)+j-1);
                    }
                }
            }
        }
    }
    //cout<<start<<" "<<end<<"\n";
    bfs(start,end);
}
