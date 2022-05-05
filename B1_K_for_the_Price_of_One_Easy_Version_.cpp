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
    int w;
    cin>>w;
    while(w--){
        int n,p,k;
        cin>>n>>p>>k;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        vi sum1,sum2;
        sum1.pb(a[0]);
        sum2.pb(a[1]);
        for(int i=2;i<n;i++){
            if(i%2==0){
                sum1.pb(a[i]+sum1[sum1.size()-1]);
            }
            else{
                sum2.pb(a[i]+sum2[sum2.size()-1]);
            }
        }
        int i1=-1,i2=-1;
        for(auto i:sum1){
            if(i>p){
                break;
            }
            else{
                i1++;
            }
        }
        for(auto i:sum2){
            if(i>p){
                break;
            }
            else{
                i2++;
            }
        }
        int ans=0;
        ans=max(2*i1+1,2*i2+2);
        ans=max((int)0,ans);
        cout<<ans;
        cout<<"\n";
    }
}