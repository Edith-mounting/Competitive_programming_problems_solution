#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
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
bool comp(int x,int y){
    return absk(x)<absk(y);
}
int32_t main() 
{
    int w;
    cin>>w;
    while (w--)
    {
        int n;
        cin>>n;
        vi a,b;
        for(int i=0;i<2*n;i++){
            int x,y;
            cin>>x>>y;
            if(x==0){
                a.pb(y);
            }
            else{
                b.pb(x);
            }
        }
        sort(a.begin(),a.end(),comp);
        sort(b.begin(),b.end(),comp);
        /*for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }*/
        long double d=0;
        for(int i=0;i<n;i++){
            d+=(double)sqrt(a[i]*a[i] + b[i]*b[i]);
        } 
        cout<<fixed;
        cout<<setprecision(10)<<d<<"\n";
    }
}