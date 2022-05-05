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
    int n;
    cin>>n;
    vi ans;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(n/i ==i){
                if(n/i >2){
                    ans.pb(i);
                }
            }
            else{
                if(n/i >2){
                    ans.pb(i);
                }
                if(i>2){
                    ans.pb(n/i);
                }
            }
        }
    }
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool bl=false;
    // for(int i:ans){
    //     cout<<i<<" ";
    // }
    // cout<<"\n";
    for(int j=0;j<ans.size();j++){
        bool b=true;
        for(int i=0;i<ans[j];i++){
            int x=i;
            while(x<n){
                b=(b&a[x]);
                x=x+ans[j];
            }
            if(b){
                bl=true;
                //cout<<j<<" ";
                break;
            }
        }
        if(bl){
            break;
        }
    }
    if(bl){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    cout<<"\n";
}