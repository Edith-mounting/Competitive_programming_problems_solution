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
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int absk(int x){
    if(x<0){
        return -x;
    }
    return x;
}

int32_t main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=(s[i]-'0');
    }
    for(int i=k;i<n;i++){
        if(a[i]==a[i-k]){
            continue;
        }
        else if(a[i-k]>a[i]){
            break;
        }
        else{
            for(int j=k-1;j>=0;j--){
                if(a[j]!=9){
                    a[j]++;
                    break;
                }
                else{
                    a[j]=0;
                }
            }
            break;
        }
    }
    for(int i=k;i<n;i++){
        a[i]=a[i-k];
    }
    cout<<n<<"\n";
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}