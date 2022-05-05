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
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)*x);
    }
}
// struct help{
//     int x,y;
// };
int32_t main()
{
	FIO;
    int n,sx,sy;
    cin>>n>>sx>>sy;
    vi v((int)4,0);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(x>=sx+1){
            v[0]++;
        }
        if(x<=sx-1){
            v[1]++;
        }
        if(y>=sy+1){
            v[2]++;
        }
        if(y<=sy-1){
            v[3]++;
        }
    }
    int maxi=0;
    for(int i=0;i<4;i++){
        maxi=max(maxi,v[i]);
    }
    int i1;
    for(int i=0;i<4;i++){
        if(v[i]==maxi){
            i1=i;
        }
    }
    cout<<maxi<<"\n";
    if(i1==0){
        cout<<sx+1<<" "<<sy;
    }
    else if(i1==1){
        cout<<sx-1<<" "<<sy;
    }
    else if(i1==2){
        cout<<sx<<" "<<sy+1;
    }
    else{
        cout<<sx<<" "<<sy-1;
    }
    cout<<"\n";
}