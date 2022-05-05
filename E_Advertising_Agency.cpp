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
int ncr(int n, int r, int p) 
{ 
	// Optimization for the cases when r is large 
	if (r > n - r) 
		r = n - r; 

	// The array C is going to store last row of 
	// pascal triangle at the end. And last entry 
	// of last row is nCr 
	vi C(r+1,0); 
	//memset(C, 0, sizeof(C)); 

	C[0] = 1; // Top row of Pascal Triangle 

	// One by constructs remaining rows of Pascal 
	// Triangle from top to bottom 
	for (int i = 1; i <= n; i++) { 

		// Fill entries of current row using previous 
		// row values 
		for (int j = min(i, r); j > 0; j--) 

			// nCj = (n-1)Cj + (n-1)C(j-1); 
			C[j] = (C[j] + C[j - 1]) % p; 
	} 
	return C[r]; 
} 
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n,greater<int>());
        int b=false;
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]){
                b=true;
            }
        }
        if(b){
            int kl=a[k-1];
            int count1=0;
            int value=0;
            for(int i=k-1;i>=0;i--){
                if(a[i]==kl){
                    value++;
                }
            }
            for(int i=0;i<n;i++){
                if(a[i]==kl){
                    count1++;
                }
            }
            cout<<ncr(count1,value,mod);
        }
        else{
            cout<<ncr(n,k,mod);
        }
        cout<<"\n";
    } 
}