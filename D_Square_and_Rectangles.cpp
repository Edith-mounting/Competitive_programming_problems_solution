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
    int area=0;
    int minix=inf,maxix=0,miniy=inf,maxiy=0;
    int x1,y1,x2,y2;
    for(int i=0;i<n;i++){
        cin>>x1>>y1>>x2>>y2;
        area+=(y2-y1)*(x2-x1);
        minix=min(minix,x1);
        maxix=max(maxix,x2);
        miniy=min(miniy,y1);
        maxiy=max(maxiy,y2);
    }
    int k1=maxix-minix,k2=maxiy-miniy;
    int a=(maxix-minix)*(maxiy-miniy);
    if((a==area) && (k1==k2)){
        cout<<"YES";
        return;
    }
    cout<<"NO";
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
