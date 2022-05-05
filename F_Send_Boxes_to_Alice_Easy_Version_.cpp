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
int N=1e5 +2;
void solve(){
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum==1){
        cout<<-1;
        return ;
    }
    vi v(N,true);
    v[0]=false;
    v[1]=false;
    for(int i=2;i<N;i++){
        if(v[i]){
            for(int j=i*2;j<N;j+=i){
                v[j]=false;
            }
        }
    }
    vi prime;
    for(int i=0;i<N;i++){
        if(v[i]){
            prime.pb(i);
        }
    }
    int k;
    for(int i=0;i<prime.size();i++){
        if(sum%prime[i]==0){
            k=prime[i];
            break;
        }
    }
    vi po;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            po.pb(i);
        }
    }
    
    int ans=0;
    int x=po.size()/k;
    vi m[x];
    for(int i=0;i<po.size();i+=k){
        for(int j=i;j<i+k;j++){
            m[i/k].pb(po[j]);
        }
    }
    for(int i=0;i<x;i++){
        if(k==2){
            ans+=(m[i][1]-m[i][0]);
        }
        else{
            for(int j=0;j<k;j++){
                ans+=absk(m[i][j]-m[i][k/2]);
            }
        }
    }
    cout<<ans;
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
