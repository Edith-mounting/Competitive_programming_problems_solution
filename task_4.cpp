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
const int n=(int)1e6 +10;
struct da{
    int index,prime,l;
};
int32_t main(){
    vector<int> v(n,0);
    v[0]=0;
    v[1]=1;
    for(int i=2;i<n;i++){
        if(v[i]==0){
            v[i]=i;
            for(int j=i*2;j<n;j+=i){
                if(v[j]==0){
                    v[j]=i;
                }
            }
        }
    }
    vector<set<int>> vl(n); 
    vector<da> q;
    int w;
    cin>>w;
    for(int i=0;i<w;i++){
        int p,l,r;
        cin>>p>>l>>r;
        vl[p].insert(l);
        vl[p].insert(r);
        q.pb({i,p,l});
        q.pb({i,p,r});
    }
    int N=1000000;
    int sieve_Prime[n] = { 0 };
    int sieve_count[n] = { 0 };
    for(int i=2;i<n;i++){
        if(sieve_Prime[i]==0){
            vl[i].insert(N);
            int pre=i*2;
            for(auto j:vl[i]){
                if(sieve_Prime[j]==0){
                    sieve_Prime[j]=i;
                    sieve_count[i]++;
                }
            }
        }
    }
}