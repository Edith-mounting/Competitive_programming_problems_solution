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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main() 
{
    int N=1001;
    vector<vi> v(N);
    v[1].pb(-1);
    v[2].pb(-1);
    v[3].pb(-1);
    v[4].pb(2);
    v[4].pb(4);
    v[4].pb(1);
    v[4].pb(3);
    for(int i=5;i<N;i++){
        if(i%4==1){
            for(auto j:v[i-1]){
                v[i].pb(j);
            }
            v[i].pb(i);
        }
        else if(i%4==2){
            for(int j:v[i-2]){
                v[i].pb(j);
            }
            v[i][i-3]=i-1;
            v[i].pb(i-3);
            v[i].pb(i);
        }
        else if(i%4==0){
            for(auto j:v[i-4]){
                v[i].pb(j);
            }
            v[i].pb(i-2);
            v[i].pb(i);
            v[i].pb(i-3);
            v[i].pb(i-1);
        }
        else{
            for(int j:v[i-3]){
                v[i].pb(j);
            }
            int k=v[i][v[i].size()-2];
            v[i][v[i].size()-2]=v[i][v[i].size()-4];
            v[i][v[i].size()-4]=k;
            v[i][v[i].size()-1]=(i-1);
            v[i].pb(i-4);
            v[i].pb(i-2);
            v[i].pb(i);
        }
    }
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        for(int i:v[n]){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}