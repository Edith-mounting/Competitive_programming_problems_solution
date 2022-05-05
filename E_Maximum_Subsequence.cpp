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
int absk(int k){
    if(k<0)return -k;

    return k;
}
int X[2000005],Y[2000005];
int n,m;
// Find all possible sum of elements of a[] and store
// in x[]
void calcsubarray(int a[], int x[], int n, int c)
{
    for (int i=0; i<(1<<n); i++)
    {
        int s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                s = (s+a[j+c])%m;
        x[i] = s%m;
    }
}
 
// Returns the maximum possible sum less or equal to S
int solveSubsetSum(int a[], int n, int S)
{
    // Compute all subset sums of first and second
    // halves
    calcsubarray(a, X, n/2, 0);
    calcsubarray(a, Y, n-n/2, n/2);
 
    int size_X = 1<<(n/2);
    int size_Y = 1<<(n-n/2);
 
    // Sort Y (we need to do doing binary search in it)
    sort(Y, Y+size_Y);
 
    // To keep track of the maximum sum of a subset
    // such that the maximum sum is less than S
    int max = 0;
 
    // Traverse all elements of X and do Binary Search
    // for a pair in Y with maximum sum less than S.
    for (int i=0; i<size_X; i++)
    {
        if (X[i] <= S)
        {
            // lower_bound() returns the first address
            // which has value greater than or equal to
            // S-X[i].
            int p = lower_bound(Y, Y+size_Y, S-X[i]) - Y;
 
            // If S-X[i] was not in array Y then decrease
            // p by 1
            if (p == size_Y || (Y[p]%m != (S-X[i]+m)%m))
                p--;
 
            if ((Y[p]+X[i])%m > max%m)
                max = (Y[p]+X[i])%m;
        }
    }
    return max%m;
}
 
int32_t main(){
    FIO;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        a[i]=a[i]%m;
    }
    cout<<solveSubsetSum(a,n,m-1)<<"\n";
}