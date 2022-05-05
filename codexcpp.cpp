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
const int N=(int)1e7+100;
int spf[N];
int ans[N];
int32_t main(){
    spf[1] = 1;
    for (int i=2; i<N; i++)
        spf[i] = i;
    for (int i=4; i<N; i+=2)
        spf[i] = 2;
  
    for (int i=3; i*i<N; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<N; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
    ans[1]=1;
    for(int i=2;i<N;i++){
        int k=1,kl=i;
        map<int,int> mp;
        while(kl>1){
            mp[spf[kl]]++;
            kl/=spf[kl];
        }
        for(auto j:mp){
            k=k*(pow(j.ff,j.ss+1)-1)/(j.ff-1);
            if(k>=N){
                break;
            }
        }
        if(k<N && ans[k]==-1){
            ans[k]=i;
        }
    }
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        cout<<ans[n]<<"\n";
    }
}