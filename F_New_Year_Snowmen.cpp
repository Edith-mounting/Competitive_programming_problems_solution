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
struct ff{
    int x1,x2,x3;
};
void solve(){
	int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    priority_queue<pii> g;
    for(auto i:mp){
        g.push({i.ss,i.ff});
    }
    vector<ff> ans;
    while(1){
        if(g.size()<3){
            break;
        }
        pii k1=g.top();
        g.pop();
        pii k2=g.top();
        g.pop();
        pii k3=g.top();
        g.pop();
        ans.pb({k1.ss,k2.ss,k3.ss});
        k1.ff--;
        k2.ff--;
        k3.ff--;
        if(k1.ff>0){
            g.push({k1.ff,k1.ss});
        }
        if(k2.ff>0){
            g.push({k2.ff,k2.ss});
        }
        if(k3.ff>0){
            g.push({k3.ff,k3.ss});
        }
    }

    cout<<ans.size()<<"\n";
    for(auto i:ans){
        int x[3];
        x[0]=i.x1;
        x[1]=i.x2;
        x[2]=i.x3;
        sort(x,x+3,greater<int>());
        for(int j=0;j<3;j++){
            cout<<x[j]<<" ";
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
