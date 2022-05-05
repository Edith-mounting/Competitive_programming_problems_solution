#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
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
int gcd(int a,int b){
    if(a==0 || b==0){
        return a+b;
    }
    return gcd(b, a%b);
}
void build_segtree(int segtree[], int a[], int index, int start, int end){
  if(start==end){
    segtree[index] = a[start];
    return;
  }
  int mid = (start+end)/2;
  build_segtree(segtree,a,2*index,start,mid);
  build_segtree(segtree,a,2*index+1,mid+1,end);
  segtree[index] = gcd(segtree[2*index], segtree[2*index+1]);
 // cout << index << " " << segtree[index] << '\n';
}


int query(int segtree[], int l, int r, int index, int start, int end){
  if(l>r){
    return 0;
  }
  if(l==start && end==r){
    return segtree[index];
  }
  int mid = (start+end)/2;
  int tmp1 = query(segtree, l, min(r, mid), 2*index, start, mid);
  int tmp2 = query(segtree, max(mid+1, l), r, 2*index+1, mid+1, end);
  return gcd(tmp1, tmp2);
}

void modify(int segtree[], int x, int value, int index, int start, int end){
  if(start==end){
    segtree[index] = value;
  }else{
    int mid = (start+end)/2;
    if(x<=mid){
      modify(segtree, x, value, 2*index, start, mid);
    }else{
      modify(segtree, x, value, 2*index+1, mid+1, end);
    }
    segtree[index] = gcd(segtree[2*index], segtree[2*index+1]);
  }
}
void solve(){
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

}
int32_t main(){
    int w=1;
    cin>>w;
    while(w--){
        solve();
    }    
}
