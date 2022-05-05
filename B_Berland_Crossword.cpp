#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
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
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}
bool b;
int n;
void f(int u,int d,int r,int l){
    if(u==n){
        if(d==n){
            if(min(r,l)<2){
                b=false;
            }
        }
        else if(d==n-1){
            if(min(r,l)<1){
                b=false;
            }
            if(max(r,l)<2){
                b=false;
            }
        }
        else{
            if(min(r,l)<1){
                b=false;
            }
        }
    }
    else if(u==n-1){
        if(d==n){
            if(min(r,l)<1){
                b=false;
            }
            if(max(r,l)<2){
                b=false;
            }
        }
        else if(d==n-1){
            if(r==0){
                if(l<2){
                    b=false;
                }
            }
            if(l==0){
                if(r<2){
                    b=false;
                }
            }
        }
        else{
            if(max(r,l)==0){
                b=false;
            }
        }
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int u,r,d,l;
        cin>>n>>u>>r>>d>>l;
        b=true;
        f(u,d,r,l);
        f(d,u,r,l);
        f(r,l,d,u);
        f(l,r,d,u);
        if(b){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }
}