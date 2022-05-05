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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// Function to check array can be
// partition into sum of 3 equal
bool isSubsetSum(int arr[], int n, int sum)
{
    // The value of subset[i%2][j] will be true 
    // if there exists a subset of sum j in 
    // arr[0, 1, ...., i-1]
    bool subset[2][sum + 1];
  
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
  
            // A subset with sum 0 is always possible 
            if (j == 0)
                subset[i % 2][j] = true; 
  
            // If there exists no element no sum 
            // is possible 
            else if (i == 0)
                subset[i % 2][j] = false; 
            else if (arr[i - 1] <= j)
                subset[i % 2][j] = subset[(i + 1) % 2]
             [j - arr[i - 1]] || subset[(i + 1) % 2][j];
            else
                subset[i % 2][j] = subset[(i + 1) % 2][j];
        }
    }
    return subset[n % 2][sum];
}
// Driver Code
int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    bool bl=false;
    if(sum%2==0){
        bl=isSubsetSum(a, n,sum/2);
    }
    if(!bl){
        cout<<0<<"\n";
    }
    else{
        while(true){
            for(int i=0;i<n;i++){
                if(a[i]%2==1){
                    cout<<1<<"\n";
                    cout<<i+1<<"\n";
                    bl=false;
                    break;
                }
            }
            if(!bl){
                break;
            }
            else{
                for(int i=0;i<n;i++){
                    a[i]/=2;
                }
            }
        }
    }
}