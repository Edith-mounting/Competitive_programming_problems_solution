#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue> 
#include <iomanip>
using namespace std;

const int PI=3.14159265358;
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
const double pi = acos(-1);
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}
map<int,int> m;
unsigned int x,n;
unsigned int count1;
void solve(int i){
    for(auto j:m){
        if(i%j.ff==0){
            int p=i;
            int ans=0;
            ans=(log2(i)/log2(j.ff));
            count1=(count1*powd(j.ff,ans))%mod;
        }
    }
}
int32_t main(){
    count1=1;
    cin>>x>>n;
    int k1=x;
    for(int i=2;i*i<=x;i++){
        if(k1%i==0){
            while(k1%i==0){
                k1/=i;
                m[i]++;
            }
        }
    }
    if(k1>1){
        m[k1]++;
    }
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            if(x/i ==i){
                if(i<=n){
                    solve(i);
                }
            }
            else{
                if(i<=n){
                    solve(i);
                }
                if(x/i <=n){
                    solve(x/i);
                }
            }
        }
    }
    cout<<count1<<"\n";
}