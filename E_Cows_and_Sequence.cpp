#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <iomanip>
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
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2);
        return (((t*t)%mod)*x)%mod;
    }
}
int N=2*(1e5) +5;
void solve(){
    int t;
    cin>>t;
    int sum=0;
    vi v(N,0);
    v.pb(0);
    vi vl(N,0);
    int sz=1;
    for(int i=0;i<t;i++){
        int p;
        cin>>p;
        if(p==1){
            int a,x;
            cin>>a>>x;
            sum=sum+a*x;
            vl[a]+=x;
        }
        else if(p==2){
            int k;
            cin>>k;
            sum+=k;
            sz++;
            v[sz-1]=k;
        }
        else{
            if(sz>=2){
                sum=sum-v[sz-1]-vl[sz];
                //cout<<v[sz-1]<<" ";
                vl[sz-1]+=vl[sz];
                vl[sz]=0;
                sz--;
            }
        }
        cout<<ps((double)sum/sz,6);
        cout<<"\n";
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
