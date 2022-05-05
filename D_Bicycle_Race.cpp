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
        return (t*t*x);
    }
}
int ans;
void f(int k1,int k2){
    if(k1==1 && k2==4){
        ans++;
    }
    if(k1==2 && k2==1){
        ans++;
    }
    if(k1==3 && k2==2){
        ans++;
    }
    if(k1==4 && k2==3){
        ans++;
    }
}
void solve(){
	int n;
    cin>>n;
    ans=0;
    vector<pii> v(n+1);
    for(int i=0;i<n+1;i++){
        cin>>v[i].ff>>v[i].ss;
    }
    int final_;
    int dir=1;//1->north,2->east,3->south,4->west
    for(int i=1;i<n;i++){
        int k1=v[i].ff-v[i-1].ff;
        int k2=v[i].ss-v[i-1].ss;
        if(k1==0){
            if(k2>0){
                final_=1;
            }
            else{
                final_=3;
            }
        }
        else{
            if(k1>0){
                final_=2;
            }
            else{
                final_=4;
            }
        }
        f(dir,final_);
        dir=final_;
    }
    cout<<ans<<"\n";
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
