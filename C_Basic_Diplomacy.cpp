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
#define mod             998244353
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
bool cmp(pair<vi,int> a,pair<vi,int> b){
    return a.ff.size() < b.ff.size();
}
int32_t main() {
    FIO;
    int w;
    cin>>w;
    while(w--){
        int n,m;
        cin>>n>>m;
        pair<vector<int>,int> v[m];
        for(int i=0;i<m;i++){
            int k;
            cin>>k;
            v[i].ss=i;
            for(int j=0;j<k;j++){
                int p;
                cin>>p;
                v[i].ff.pb(p);
            }
        }
        sort(v,v+m,cmp);
        vector<int> ans(m);
        vi x(n+1,0);
        for(int i=0;i<m;i++){
            sort(v[i].ff.begin(),v[i].ff.end());
        }
        bool b=true;
        for(int i=0;i<m;i++){
            bool bl=false;
            for(int j:v[i].ff){
                if(x[j]< (m+1)/2){
                    x[j]++;
                    ans[v[i].ss]=j;
                    bl=true;
                    break;
                }
            }
            if(!bl){
                b=false;
                break;
            }
        }
        if(b){
            cout<<"YES\n";
            for(int i:ans){
                cout<<i<<" ";
            }
        }
        else{
            cout<<"NO";
        }   
        cout<<"\n";
    }
}