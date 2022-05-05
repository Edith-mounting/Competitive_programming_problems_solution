#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
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
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int N=1000+5;
int f(int x,vi& par){
    if(par[x]==x) return x;
    else return par[x]=f(par[x],par);
}
void merg(int a,int b,vi& par,vi& sz){
    int pa=f(a,par),pb=f(b,par);
    if(pa==pb)return ;

    if(sz[pa]>sz[pb]){
        sz[pa]+=sz[pb];
        par[pb]=pa;
    }else{
        sz[pb]+=sz[pa];
        par[pa]=pb;
    }
    return;
}
void solve(){
    int n,j;
    cin>>n>>j;
    int count=0;
    char s[n+1];
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    bool bl=true;
    for(int i=j;i<=n;){
        if(count>=i){
            bl=false;
            break;
        }
        else{
            if(s[i]=='#'){
                s[i]='.';
            }
            else{
                i++;
            }
            count++;
        }
    }
    if(bl){
        cout<<"JAY";
    }
    else{
        cout<<"JEFF";
    }
    cout<<"\n";
}
int32_t main(){
    int w=1;
    cin>>w;
    while(w--){
        solve();
    }    
}
