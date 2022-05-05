#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
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
int CeilIndex(std::vector<int>& v, int l, int r, int key) 
{ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    } 
  
    return r; 
} 
int LongestIncreasingSubsequenceLength(std::vector<int>& v) 
{ 
    if (v.size() == 0) 
        return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1;
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) {  
        if (v[i] < tail[0]) 
            tail[0] = v[i];  
        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
    } 
  
    return length; 
} 
int32_t main(){
    int n,q,s;
    cin>>n>>q>>s;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int last=0;
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        int l=(x + s*last)%n;
        int r=(y + s*last)%n;
        if(l>r){
            int k=l;
            l=r;
            r=k;       
        }
        vector<int> v;
        for(int i=l;i<=r;i++){
            v.push_back(a[i]);
        }
        last=LongestIncreasingSubsequenceLength(v);
        cout<<last<<"\n";
    }
}