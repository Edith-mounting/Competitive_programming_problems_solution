#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <stack>
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
#define w(x)            int x; cin>>x; whiles(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int n,m,k;
vi g;
vi ans;
void printTheArray(int a[], int n,int x[][3], int m)
{
    int c=0;
    for(int i=0;i<n;i++){
        c+=g[i]*a[i];
    }
    for(int i=0;i<m;i++){
        int q=1;
        for(int j=x[i][0]-1;j<x[i][1];j++){
            q=q*a[j];
        }
        q=q*x[i][2];
        c+=q;
    }
    ans.pb(c);
}
void generateAllBinaryStrings(int n, int arr[], int i,int x[][3],int m)
{
    if (i == n) {
        printTheArray(arr, n, x, m);
        return;
    }
    arr[i] = 0;
    generateAllBinaryStrings(n, arr, i + 1,x,m);

    arr[i] = 1;
    generateAllBinaryStrings(n, arr, i + 1,x,m);
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        ans.clear();
        cin>>n>>m>>k;;
        g.clear();
        g.resize(n,0);
        int x[m][3];
        for(int i=0;i<n;i++){
            cin>>g[i];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<3;j++){
                cin>>x[i][j];
            }
        }
        int a[n];
        generateAllBinaryStrings(n, a, 0,x,m);
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        for(int i=0;i<k;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
} 