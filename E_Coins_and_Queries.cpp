#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue> 
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
    FIO;
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    while(q--){
        int k;
        cin>>k;
        bool b=true;
        int k1=floor(log2(k));
        k1=pow(2,k1);
        int ans=0;
        while(1){
            if(mp.find(k1)!=mp.end()){
                int p=k/k1;
                ans+=min(p,mp[k1]);
                k=k-min(p,mp[k1])*k1;
                if(k==0){
                    break;
                }
            }
            k1/=2;
            if(k1==0){
                break;
            }
        }
        if(k==0){
            cout<<ans;
        }
        else{
            cout<<-1;
        }
        cout<<"\n";
    }
}