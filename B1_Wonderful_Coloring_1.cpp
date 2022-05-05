#include <iostream>
#include <algorithm>
#include <map>
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

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        string s;
        cin>>s;
        int n=s.length();
        vi a(26,0);
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
        }
        int ans=0,q=0;
        for(int i=0;i<26;i++){
            if(a[i]>1){
                ans++;
            }
            else if(a[i]==1){
                q++;
            }
        }
        ans+=(q/2);
        cout<<ans<<"\n";
    }
}