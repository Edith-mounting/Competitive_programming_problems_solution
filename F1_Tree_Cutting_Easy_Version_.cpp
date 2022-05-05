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
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2);
        return (((t*t)%mod)*x)%mod;
    }
}
int n,ans=0;
vector<vi> adj;
vi cal,a;
int dfs(int i,int par,int col){
    int x=0;
    for(int j:adj[i]){
        if(j!=par){
            x+=dfs(j,i,col);
        }
    }
    if(a[i]==col){
        x++;
    }
    cal[i]=x;
    return x;
}
int32_t main()
{
	FIO;
    cin>>n;
    a.resize(n+1);
    adj.resize(n+1);
    cal.resize(n+1);
    int blue=0,red=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];        //a[i]=2 means blue, a[i]=1 means red
        if(a[i]==1){
            red++;
        }
        if(a[i]==2){
            blue++;
        }
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(blue>=2 && red>=2){
        ans=0;
    }
    else if(blue==0 || red==0){
        ans=n-1;
    }
    else if(blue==1 && red==1){
        int bluenode;
        for(int i=1;i<=n;i++){
            if(a[i]==2){
                bluenode=i;
            }
        }
        cal[bluenode]=dfs(bluenode,-1,1);
        for(int i=1;i<=n;i++){
            if(cal[i]>=red){
                ans++;
            }
        }
        ans--;
    }
    else{
        if(blue==1){
            int bluenode;
            for(int i=1;i<=n;i++){
                if(a[i]==2){
                    bluenode=i;
                }
            }
            cal[bluenode]=dfs(bluenode,-1,1);
            //cout<<"red\n";
            for(int i=1;i<=n;i++){
            //    cout<<cal[i]<<" ";
                if(cal[i]>=red){
                    ans++;
                }
            }
            //cout<<"\n";
        }
        else{
            int rednode;
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    rednode=i;
                }
            }
            cal[rednode]=dfs(rednode,-1,2);
            //cout<<"blue\n";
            for(int i=1;i<=n;i++){
            //    cout<<cal[i]<<" ";
                if(cal[i]>=blue){
                    ans++;
                }
            }
            //cout<<"\n";
        }
        ans--;
    }
    cout<<ans<<"\n";
}