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
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)*x);
    }
}
void solve(){
    int n;
    cin>>n;
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].ff>>v[i].ss;
    }
    vi ans;
    int N=1e6 +5;
    vi x(N,0);
    for(int i=0;i<n;i++){
        x[v[i].ff]++;
        x[v[i].ss]++;
    }
    int x1=-1,x2;
    for(int i=0;i<N;i++){
        if(x[i]==1){
            if(x1==-1){
                x1=i;
            }
            else{
                x2=i;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(x1==v[i].ff){
            ans.pb(x1);
            break;
        }
        
        if(x2==v[i].ff){
            ans.pb(x2);
            x2=x1;
            break;
        }
    }
    
}
int32_t main()
{
	FIO;
	int w=1;
	//cin>>w;
	while(w--){
		solve();
	}
}
