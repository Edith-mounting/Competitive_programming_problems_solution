#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
        return (((t*t)%mod)*(x))%mod;        
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int N=400005;
        vector<bool> v(N,true);
        int k=2;
        int a[n],b[n];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=1;i<=n;i++){
            if(i==b[i-1]){
                if(v[k]){
                    a[i-1]=k;
                    v[k]=false;
                    k++;
                }
                else{
                    while(!v[k]){
                        k++;
                    }
                    a[i-1]=k;
                    v[k]=false;
                    k++;
                }
            }
            else{
                if(v[k]){
                    a[i-1]=k;
                    a[b[i-1]-1]=k*2;
                    v[k]=false;
                    v[k*2]=false;
                    k++;
                }
                else{
                    while(!v[k]){
                        k++;
                    }
                    a[i-1]=k;
                    a[b[i-1]-1]=k*2;
                    v[k]=false;
                    v[k*2]=false;
                    k++;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}