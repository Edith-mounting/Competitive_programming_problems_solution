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
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int n;
    cin>>n;
    int k=n;
    if(n==1){
        cout<<1<<" "<<0<<"\n";
    }
    else{
    map<int,int> mp;
    for(int i=2;i*i<=k;i++){
        if(n%i==0){
            while(n%i==0){
                mp[i]++;
                n/=i;
            }
        }
    }
    if(n>1){
        mp[n]++;
    }
    int kl=1;
    vi ans;
    for(auto i:mp){
        ans.pb(i.ss);
        kl=kl*(i.ff);
    }
    cout<<kl<<" ";
    int count=0;
    sort(ans.begin(),ans.end());
    if(ans[0]==ans[ans.size()-1]){
        if(pow(2,ceil(log2(ans[0])))==(ans[0])){
            count+=ceil(log2(ans[0]));
        }
        else{
            count+=ceil(log2(ans[0]))+1;
        }
    }
    else{
        count+=ceil(log2(ans[ans.size()-1]))+1;
    }
    cout<<count<<"\n";}
}