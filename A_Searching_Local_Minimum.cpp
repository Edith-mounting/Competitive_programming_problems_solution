#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
vi a;
int localMinUtil(int low, int high, int n)
{
    // Find index of middle element
    int mid = low + (high - low)/2;  /* (low + high)/2 */
    
    if(a[mid]==-1){
        cout<<"? "<<mid<<endl;
        cin>>a[mid];
    }

    if(a[mid-1]==-1){
        cout<<"? "<<mid-1<<endl;
        cin>>a[mid-1];
    }

    if(a[mid+1]==-1){
        cout<<"? "<<mid+1<<endl;
        cin>>a[mid+1];
    }
    // Compare middle element with its neighbours
    // (if neighbours exist)
    if ((mid == 1 || a[mid-1] > a[mid]) &&
            (mid == n || a[mid+1] > a[mid]))
        return mid;
  
    // If middle element is not minima and its left
    // neighbour is smaller than it, then left half
    // must have a local minima.
    else if (mid > 1 && a[mid-1] < a[mid])
        return localMinUtil(low, (mid -1), n);
  
    // If middle element is not minima and its right
    // neighbour is smaller than it, then right half
    // must have a local minima.
    return localMinUtil((mid + 1), high, n);
}
void localMin(int n)
{
    int ans=localMinUtil(1, n, n);
    cout<<"! "<<ans<<endl;
}
int32_t main() {
    int n;
    cin>>n;
    a.resize(n+2);
    a[0]=inf;
    a[n+1]=inf;
    for(int i=1;i<=n;i++){
        a[i]=-1;
    }
    localMin(n);
}