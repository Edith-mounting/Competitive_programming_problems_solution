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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int i1=0,i2=0;
    for(int i=0;i<n;i++){
        if(a[i]!=(i+ 1)){
            if(i1==0){
                i1=i+1;
                i2=i1;
                for(int j=i+1;j<n;j++){
                    if(a[j]== a[j-1]-1){
                        i2++;
                        continue;
                    }
                    else{
                        break;
                    }
                }
                break;
            }
            else{
                continue;
            }
        }
        else{
            continue;
        }
    }
    vector<int> v;
    for(int i=0;i<i1-1;i++){
        v.pb(a[i]);
    }
    for(int i=i2-1;i>=i1-1;i--){
        v.pb(a[i]);
    }
    for(int i=i2;i<n;i++){
        v.pb(a[i]);
    }
    bool b=true;
    for(int i=0;i<n;i++){
        if(v[i]!=i+1){
            b=false;
            break;
        }
    }
    if(!b){
        cout<<0<<" "<<0;
    }
    else{
        cout<<i1<<" "<<i2;
    }
    cout<<"\n";
}