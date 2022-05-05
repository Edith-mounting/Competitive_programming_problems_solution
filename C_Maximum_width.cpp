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

int32_t main(){
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vi left(m,0);
    vi right(m,0);
    int j=0;
    for(int i=0;i<n;i++){
        if(s[i]==t[j]){
            left[j]=i;
            j++;
        }
        if(j==m){
            break;
        }
    }
    j=m-1;
    for(int i=n-1;(i>=0);i--){
        if(s[i]==t[j]){
            right[j]=i;
            j--;
        }
        if(j<0){
            break;
        }
    }
    int maxi=0;
    for(int i=0;i<m-1;i++){
        maxi=max(right[i+1]-left[i],maxi);
    }
    cout<<maxi<<"\n";
}