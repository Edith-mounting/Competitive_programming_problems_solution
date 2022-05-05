#include<iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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

// C++ program to print all possible
// substrings of a given string

// Function to print all sub strings
int powd(int k){
    return pow(2,floor(log2(k)));
}

// Driver program to test above function
int32_t main() 
{
	
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int i=0,j,gop2;
        while(true){
            if(x==0){
                break;
            }
            while(i<n-1 && a[i]==0){
                i++;
            }
            if(i==n-1){
                break;
            }
            gop2=powd(a[i]);
            a[i]=a[i]^gop2;
            j=i+1;
            while(true){
                if(j==n-1){
                    a[j]=a[j]^gop2;
                    break;
                }
                if(a[j]^gop2 < a[j]){
                    a[j]=a[j]^gop2;
                    break;
                }
                j++;
            }
            x--;
        }
        if(x==1 || (x%2!=1 && n==2)){
            a[n-1]^=1;
            a[n-2]^=1;
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}

