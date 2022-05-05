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
    FIO;
    int w=1;
    //cin>>w;
    while(w--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int a[26]={};
        for(int i=0;i<n;i++){
            a[s[i]-'A']++;
        }
        sort(a,a+26,greater<int>());
        int ans=0;
        for(int i=0;i<26;i++){
            //cout<<a[i]<<" "<<k<<"\n";
            if(a[i]<=k){
                ans+=a[i]*a[i];
                k-=a[i];
            }
            else{
                ans+=k*k;
                k=0;
                break;
            }

            //cout<<ans<<"\n";
            if(k<=0){
                break;
            }
        }
        cout<<ans<<"\n";
    }
}