#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
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
#define pqs             priority_queue<int,vi,greater<int> >//for min-heap in cpp
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class union_find{
    int n;
    vector<int> par;
    vector<int> sz;
    public:
        union_find(int val){
            n=val;
            par.resize(n+1);
            sz.resize(n+1);
            for(int i=1;i<=n;i++){
                par[i]=i;
                sz[i]=1;
            }
        }
        int root(int a){
            if(a==par[a])
                return a;
            
            return par[a]=(root(par[a]));
        }
        bool find(int a,int b){
            return root(a)==root(b);
        }
        int un(int a,int b){
            int ra=root(a);
            int rb=root(b);
            if(ra==rb){
                return 0;
            }
            if(sz[ra]>sz[rb]){
                swap(ra,rb);
            }
            par[ra]=rb;
            sz[rb]+=sz[ra];
            return 1;
        }
};
int32_t main(){
    int n;
    cin>>n;
    string s[n];
    vector<int> a[26];
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].length();j++){
            a[s[i][j]-'a'].pb(i +1);
        }
    }
    int connected=n;
    for(int i=0;i<26;i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    union_find dsu(n);
    for(int i=0;i<26;i++){
        for(int j=0;j<a[i].size()-1;j++){
            int u=a[i][j];
            int v=a[i][j+1];
            connected=connected-dsu.un(u,v);
        }
    }
    cout<<connected;
}