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
int absk(int k){
    if(k<0)return -k;

    return k;
}
int32_t main(){
    int n;
    cin>>n;
    vector<int> v;
    v.pb(1);
    int N=1;
    while(N<=1000000){
        int k=v.size(),i1;
        int kl=v[k-1];
        int q=0;
        while(kl>0){
            q++;
            kl/=10;
        }
        for(int i=0;i<k;i++){
            if(v[i]==pow(10,q-1)){
                i1=i;break;
            }
        }
        for(int i=i1;i<k;i++){
            int p,q;
            p=v[i]*10;
            q=v[i]*10 +1;
            if(q<=1000000){
                v.pb(p);
                v.pb(q);
            }
            else{
                N=1000002;
                break;
            }
        }
    }
    N=1000000+1;
    set<int> s;
    for(int i=0;i<v.size();i++){
        s.insert(v[i]);
    }
    s.insert(1000000);
    v.clear();
    for(auto i:s){
        v.pb(i);
    }
    vector<pii> ans(N,{inf,0});
    ans[0]={0,0};
    for(int i=1;i<N;i++){
        for(int j=0;j<v.size();j++){
            if(i-v[j] >=0){
                if(ans[i].ff> ans[i-v[j]].ff+1){
                    ans[i].ff=ans[i-v[j]].ff+1;
                    ans[i].ss=i-v[j];
                }
            }
        }
    }
    cout<<ans[n].ff<<"\n";
    vi put;
    while(n!=0){
        put.pb((n-ans[n].ss));
        n=ans[n].ss;
    }
    sort(put.begin(),put.end());
    for(auto i:put){
        cout<<i<<" ";
    }
}