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
#define MAXN   1000005
int spf[MAXN];
int32_t main(){
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
  
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
  
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
  
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
    int w=1;
    while(w--){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<" "<<0<<"\n";
        continue;
    }
    map<int,int> mp;
    while(n>1){
        mp[spf[n]]++;
        n/=spf[n];
    }
    int k=1;
    vi ans;
    for(auto i:mp){
        k=k*(i.ff);
        ans.pb(i.ss);
    }
    cout<<k<<" ";
    int a;
    sort(ans.begin(),ans.end());
    int kl=ans.size()-1;
    //cout<<ceil(log2(ans[kl]))<<" ";
    if(ans[0]==ans[ans.size()-1]){
        if(pow(2,ceil(log2(ans[0])))==ans[0]){
            a=ceil(log2(ans[0]));
        }else{
            a=ceil(log2(ans[0]))+1;
        }
    }
    else{
        a=ceil(log2(ans[kl]))+1;
    }
    cout<<a<<"\n";}
}