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
struct help{
    int x1,y1,i1;
};
bool comp(pii a,pii b){
    return a.ss<b.ss;
}
void solve(){
    int n;
    cin>>n;
    vector<pii> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i].ff>>x[i].ss;
    }
    if(n<=2){
        cout<<0;
        return;
    }
    //for same y levels
    sort(x.begin(),x.end(),comp);
    vector<pair<int,vi>> v;
    vi temp;
    temp.pb(x[0].ff);
    for(int i=1;i<n;i++){
        if(x[i].ss==x[i-1].ss){
            temp.pb(x[i].ff);
        }
        else{
            sort(temp.begin(),temp.end());
            v.pb({x[i-1].ss,temp});
            temp.clear();
            temp.pb(x[i].ff);
        }
    }
    if(temp.size()!=0){
        sort(temp.begin(),temp.end());
        v.pb({x[n-1].ss,temp});
    }
    temp.clear();
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i].ff<<"\n";
    //     for(int j=0;j<(v[i].ss).size();j++){
    //         cout<<(v[i].ss)[j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    if(v.size()<=2){
        cout<<0;
        return;
    }
    int q=v.size();
    vector<int> a(q,0);
    int minix=(v[q-1].ss)[0],maxix=(v[q-1].ss)[(v[q-1].ss.size() -1)],inity=v[q-1].ff;
    for(int i=q-2;i>=1;i--){
        //Calculating a[i]
        minix=min(minix,(v[i].ss)[0]);
        maxix=max(maxix,(v[i].ss)[(v[i].ss.size() -1)]);
        a[i]=(maxix-minix)*(inity-v[i].ff);
    }
    // for(int i=0;i<q;i++){
    //     cout<<a[i]<<" ";
    // }
    int ans=inf;
    minix=(v[0].ss)[0],maxix=(v[0].ss)[(v[0].ss.size() -1)],inity=v[0].ff;
    for(int i=0;i<q-1;i++){
        minix=min(minix,(v[i].ss)[0]);
        maxix=max(maxix,(v[i].ss)[(v[i].ss.size() -1)]);
        ans=min(ans,(maxix-minix)*(v[i].ff-inity)+a[i+1]);
    }
    //for same x levels
    sort(x.begin(),x.end());
    v.clear();
    temp.pb(x[0].ss);
    for(int i=1;i<n;i++){
        if(x[i].ff==x[i-1].ff){
            temp.pb(x[i].ss);
        }
        else{
            sort(temp.begin(),temp.end());
            v.pb({x[i-1].ff,temp});
            temp.clear();
            temp.pb(x[i].ss);
        }
    }
    if(temp.size()!=0){
        sort(temp.begin(),temp.end());
        v.pb({x[n-1].ff,temp});
    }
    temp.clear();
    if(v.size()<=2){
        cout<<0;
        return;
    }
    q=v.size();
    vi b(q,0);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i].ff<<"\n";
    //     for(int j=0;j<(v[i].ss).size();j++){
    //         cout<<(v[i].ss)[j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    minix=(v[q-1].ss)[0],maxix=(v[q-1].ss)[(v[q-1].ss.size() -1)],inity=v[q-1].ff;
    for(int i=q-2;i>=1;i--){
        //Calculating a[i]
        minix=min(minix,(v[i].ss)[0]);
        maxix=max(maxix,(v[i].ss)[(v[i].ss.size() -1)]);
        b[i]=(maxix-minix)*(inity-v[i].ff);
    }
    // for(int i=0;i<q;i++){
    //     cout<<b[i]<<" ";
    // }
    minix=(v[0].ss)[0],maxix=(v[0].ss)[(v[0].ss.size() -1)],inity=v[0].ff;
    for(int i=0;i<q-1;i++){
        minix=min(minix,(v[i].ss)[0]);
        maxix=max(maxix,(v[i].ss)[(v[i].ss.size() -1)]);
        ans=min(ans,(maxix-minix)*(v[i].ff-inity)+b[i+1]);
    }
    cout<<ans;
}
int32_t main()
{
	FIO;
	int w=1;
	cin>>w;
	while(w--){
		solve();
        cout<<"\n";
	}
}
