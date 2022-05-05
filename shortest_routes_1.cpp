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
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
vector<vi> adj;
int x,y;
vector<bool> vis;
//specially for cses as it does not include long long in int
vi par;
bool bl;
bool dfs(int i){
    vis[i]=true;
    for(int nb:adj[i]){
        if(vis[nb]){
            if(nb!=par[i]){
                x=nb;
                y=i;
                return false;
            }
            else{
                continue;
            }
        }
        else{
            par[nb]=i;
            bl=dfs(nb);
            if(!bl){
                return false;
            }
        }
    }
    return true;
}
class comp{
    public:
        bool operator()(pair<int,int> x, pair<int,int> y) {
            return x.ss>y.ss;
        }
};
int32_t main(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> p;
    p.push({1,5});
    p.push({2,4});
    p.push({3,6});
    pii x=p.top();
    p.pop();
    pii y=p.top();
    p.pop();
    cout<<x.ff<<" "<<x.ss<<"\n";
    cout<<y.ff<<" "<<y.ss<<"\n";
}
