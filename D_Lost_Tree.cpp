#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
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
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)%mod*x)%mod;
    }
}
// Driver Code
int32_t main()
{
    int n;
    cin>>n;
    vector<vi> adj;
    adj.resize(n+1);
    cout<<"? "<<1<<endl;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;
    vi even,odd;
    for(int i=2;i<=n;i++){
        if(a[i-1]==1){
            adj[1].pb(i);
            adj[i].pb(1);
        }

        if(a[i-1]%2 ==1){
            odd.pb(i);
        }
        else{
            even.pb(i);
        }
    }
    if(even.size()>odd.size()){
        for(int j=0;j<odd.size();j++){
            cout<<"? "<<odd[j]<<endl;
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            for(int i=2;i<=n;i++){
                if(a[i-1]==1){
                    adj[odd[j]].pb(i);
                    adj[i].pb(odd[j]);
                }
            }
        }
    }
    else{
        for(int j=0;j<even.size();j++){
            cout<<"? "<<even[j]<<endl;
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            for(int i=2;i<=n;i++){
                if(a[i-1]==1){
                    adj[even[j]].pb(i);
                    adj[i].pb(even[j]);
                }
            }
        }
    }
    map<pii,bool> m;
    cout<<"!"<<endl;
    for(int i=1;i<n+1;i++){
        for(int j:adj[i]){
            if(m.find({max(i,j),min(i,j)})==m.end()){
                cout<<i<<" "<<j<<endl;
                m[{max(i,j),min(i,j)}]=true;
            }
        }
    }
}
