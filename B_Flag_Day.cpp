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
    int n,m;
    cin>>n>>m;
    vi v(n+1,0);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(v[a]!=0){
            if(v[a]==1){
                v[b]=2;
                v[c]=3;
            }
            else if(v[a]==2){
                v[b]=1;
                v[c]=3;
            }
            else{
                v[b]=1;
                v[c]=2;
            }
        }
        else if(v[b]!=0){
            if(v[b]==1){
                v[a]=2;
                v[c]=3;
            }
            else if(v[b]==2){
                v[a]=1;
                v[c]=3;
            }
            else{
                v[a]=1;
                v[c]=2;
            }
        }
        else if(v[c]!=0){
            if(v[c]==1){
                v[b]=2;
                v[a]=3;
            }
            else if(v[c]==2){
                v[b]=1;
                v[a]=3;
            }
            else{
                v[b]=1;
                v[a]=2;
            }
        }
        else{
            v[a]=1;
            v[b]=2;
            v[c]=3;
        }
    }
    for(int i=1;i<n+1;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}