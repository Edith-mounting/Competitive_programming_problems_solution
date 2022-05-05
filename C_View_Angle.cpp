#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <cmath>
#include <queue> 
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
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
const double pi = acos(-1);
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int n;
    cin>>n;
    vector<double> v(n);
    for(int i=0;i<n;i++){
        double x,y;
        cin>>x>>y;
        v[i]=(double)(atan2(y,x)*180)/pi;
    }
    
    if(n==1){
        cout<<ps((double)0,10);
    }
    else{
        sort(v.begin(),v.end());
        double mini=(double)(v[n-1]-v[0]);
        for(int i=1;i<v.size();i++){
            mini=min(mini,(double)(360-(v[i]-v[i-1])));
        }
        cout<<ps(mini,10);
    }
}