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
vector<bool> vis;
vi parent,sz;
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int32_t main()
{
	FIO;
    int w;
    cin>>w;
    while(w--){
        int n,m;
        cin>>n>>m;
        parent.clear();
        sz.clear();
        vis.clear();
        vis.resize(n+1,false);
        parent.resize(n+1);
        sz.resize(n+1);

        for(int i=1;i<=n;i++){
            make_set(i);
        }
        
        for(int i=0;i<m;i++){
            int l,r;
            cin>>l>>r;
            union_sets(l,r);
        }
        // for(int i=1;i<=n;i++){
        //     cout<<find_set(i)<<" ";
        // }
        // cout<<"\n";
        vi v1;
        for(int i=1;i<=n;i++){
            int set_parent=find_set(i);
            if(!vis[set_parent]){
                int q=sz[set_parent];
                vis[set_parent]=true;
                v1.pb(q);
            }
        }
        int sum=0;
        for(int i=1;i<v1.size();i++){
            sum+=v1[i];
        }
        int ans=0;
        for(int i=0;i<v1.size()-1;i++){
            ans+=v1[i]*sum;
            sum-=v1[i+1];
        }
        cout<<ans*2<<"\n";
    }
}