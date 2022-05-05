#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue> 
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

int32_t main(){
    int a,b;
    cin>>a>>b;
    int x=__gcd(a,b);
    vi factors;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            factors.pb(i);
            if(x/i !=i){
                factors.pb(x/i);
            }
        }
    }
    sort(factors.begin(),factors.end());
    // for(int  i:factors){
    //     cout<<i<<" ";
    // }
    // cout<<"\n";
    int si=factors.size();
    int n;
    cin>>n;    
    while(n--){
        int low,high;
        cin>>low>>high;
        vi::iterator lower,upper;
        //We have to find maximum value less than or equals to high which is
        //greater than low
        upper=lower_bound(factors.begin(),factors.end(),high);
        int x=upper-factors.begin();
        if(x==si){
            if(factors[x-1]>=low){
                cout<<factors[x-1];
            }
            else{
                cout<<-1;
            }
        }
        else{
            if((factors[x]<=high) && (factors[x]>=low)){
                cout<<factors[x];
            }
            else if((x-1)>=0 && (factors[x-1]<=high) && (factors[x-1]>=low)){
                cout<<factors[x-1];
            }
            else{
                cout<<-1;
            }
        }
        cout<<"\n";
    }
}