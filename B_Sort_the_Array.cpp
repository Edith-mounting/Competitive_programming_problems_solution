#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    bool bl=false;
    int i1,i2;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            bl=true;
            i1=i;
            i2=n-1;
            for(int j=i;j<n-1;j++){
                if(a[j]<=a[j+1]){
                    i2=j;
                    break;
                }
            }
            break;
        }
    }
    if(!bl){
        cout<<"yes"<<"\n";
        cout<<1<<" "<<1<<"\n";
    }
    else{
        bl=true;
        vi ans;
        for(int i=0;i<i1;i++){
            ans.pb(a[i]);
        }
        for(int i=i2;i>=i1;i--){
            ans.pb(a[i]);
        }
        for(int i=i2+1;i<n;i++){
            ans.pb(a[i]);
        }
        for(int i=0;i<n-1;i++){
            if(ans[i]>ans[i+1]){
                bl=false;
            }
        }
        if(bl){
            cout<<"yes"<<"\n";
            cout<<i1+1<<" "<<i2+1<<"\n";
        }
        else{
            cout<<"no"<<"\n";
        }
    }
}