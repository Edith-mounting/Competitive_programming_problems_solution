#include <iostream>
#include <algorithm>
#include <cmath>
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
int32_t main(){
    FIO;
    int w=1;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int sum1=0,sum2=0;
        for(int i=0;i<n- n/4;i++){
            sum1+=a[i];
            sum2+=b[i];
        }
        if(sum1>=sum2){
            cout<<0<<"\n";
            continue;
        }
        else{
            int q=ceil((sum2-sum1)/100);
            int ans=q;
            vi v;
            for(int i=0;i<n;i++){
                v.pb(a[i]);
            }
            for(int i=0;i<q;i++){
                v.pb(100);
            }
            int s=v.size();
            for(int i=0;i< s- s/4;i++){
                
            }
        }
    }
}