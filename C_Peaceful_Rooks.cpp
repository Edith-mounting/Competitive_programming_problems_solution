#include <iostream>
#include <algorithm>
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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
class dsu{
    public:
        vi p;
        int n;
        dsu(int val){
            n=val;
            p.resize(n,0);
        }
        inline int get(int x){
            return (x==p[x] ? x:(p[x]=get(p[x])));
        }
        inline bool unite(int x,int y){
            x=get(x);
            y=get(y);
            if(x!=y){
                p[x]=y;
                return true;
            }
            return false;
        }
};
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n,m,ans=0;
        cin>>n>>m;
        dsu d(n);
        vector<bool> vis(n);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            x--,y--;
            if(x==y)continue;
            bool bl=d.unite(x,y);
            vis[x]=true;
            ans++;
        }
        for(int i=0;i<n;i++){
            if((d.get(i)==i) && vis[i])ans++;
        }
        cout<<ans<<"\n";
    }
}