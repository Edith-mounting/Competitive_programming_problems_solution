#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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
struct bb{
    int x,int y,int r;
};
class union_find{
    int n;
    vector<bb> par;
    vector<bb> sz;
    public:
        union_find(int val){
            n=val;
            par.resize(n+1);
            sz.resize(n+1);
            for(int i=1;i<=n;i++){
                par[i].x=i;
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
        void un(int a,int b){
            int ra=root(a);
            int rb=root(b);
            if(ra==rb){
                return ;
            }
            if(sz[ra]>sz[rb]){
                swap(ra,rb);
            }
            par[ra]=rb;
            sz[rb]+=sz[ra];
        }
};
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int h,w,n;
        cin>>h>>w>>n;
        union_find m(n);
        for(int i=0;i<n;i++){
            int a,b,r;
            cin>>a>>b>>r;
            m[]
        }
    }
}