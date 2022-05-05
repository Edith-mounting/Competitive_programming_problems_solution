#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool>
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
struct cmp1 {
    bool operator() (pii a, pii b) const {
        return a.ff<b.ff;
    }
};
struct cmp2 {
    bool operator() (pii a, pii b) const {
        if(a.ss!=b.ss){
            return a.ss>b.ss;
        }
        else{
            return a.ff<b.ff;
        }
    }
};

int32_t main(){
    int q;
    cin>>q;
    int i=1;
    set<pii,cmp1> s1;
    set<pii,cmp2> s2;
    while(q--){
        int k;
        cin>>k;
        if(k==1){
            int m;
            cin>>m;
            s1.insert({i,m});
            s2.insert({i,m});
            i++;
        }
        else if(k==2){
            auto kl=s1.begin();
            cout<<(*kl).ff<<" ";
            s1.erase(*kl);
            s2.erase(*kl);
        }
        else{
            auto kl=s2.begin();
            cout<<(*kl).ff<<" ";
            s1.erase(*kl);
            s2.erase(*kl);
        }
    }
}