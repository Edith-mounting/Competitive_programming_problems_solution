#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
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

int32_t main(){
    int N=1000000+5;
    vector<bool> v(N,true);
    v[0]=false;
    v[1]=false;
    for(int i=2;i<N;i++){
        if(v[i]){
            for(int j=i*2;j<N;j+=i){
                v[j]=false;
            }
        }
    }
    int x=0;
    vector<int>  vl,kl;
    for(int i=3;i<N;i++){
        if(v[i]){
            if(v[i-2]){
                x++;
                vl.pb(i);
                kl.pb(x);
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<5){
            cout<<0;
        }
        else{
            vector<int>::iterator low1;
            low1=lower_bound(vl.begin(),vl.end(),n);
            int k=(low1-vl.begin());
            if(v[n]){
                if(v[n-2]){
                    cout<<kl[k];
                }
                else{
                    cout<<kl[k-1];
                }
            }
            else{
                cout<<kl[k-1];
            }
        }
        cout<<"\n";
    }
}