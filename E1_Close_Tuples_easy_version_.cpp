#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
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
int absk(int x){
    if(x<0){
        return -x;
    }
    return x;
}
int c(int x,int y,int z){
    return x*y*z;
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        vi v(n+1,0);
        for(int i=0;i<n;i++){
            int kl;
            cin>>kl;
            v[kl]++;
        }
        int count=0;
        for(int i=1;i<n+1-2;i++){
            count+=c(v[i],v[i+1],v[i+2]);
        }
        //cout<<count<<" ";
        for(int i=1;i<n+1-2;i++){
            count+=(v[i]*(v[i]-1)*(v[i+1]+v[i+2]))/2;
        }
        count+=(v[n-1]*(v[n-1]-1)*(v[n]))/2 + (v[n]*(v[n]-1)*v[n-1])/2;
        //cout<<count<<" ";
        for(int i=1;i<n+1-2;i++){
            count+=(v[i]*(v[i+1]*(v[i+1]-1)+ v[i+2]*(v[i+2]-1)))/2;
        }
        for(int i=0;i<n+1;i++){
            count+=(v[i]*(v[i]-1)*(v[i]-2))/6;
        }
        cout<<count<<"\n";
    }   
}