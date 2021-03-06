#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue> 
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
    int a[n*n];
    for(int i=0;i<n*n;i++){
        cin>>a[i];
    }
    multiset<int> s;
    for(int i=0;i<n*n;i++){
        s.insert(a[i]);
    }
    vi ans;
    multiset<int> :: iterator it;
    int x=0;
    it=s.end();
    it--;
    ans.pb(*it);
    s.erase(s.find(*it));
    vi del;
    del.pb(ans[0]);
    x++;
    while(x<n){
        it=s.end();
        it--;
        int maxi2=*it;
        ans.pb(maxi2);
        s.erase(s.find(*it));
        for(int i=0;i<del.size();i++){
            int q=__gcd(maxi2,del[i]);
            s.erase(s.find(q));
            s.erase(s.find(q));
        }
        del.pb(maxi2);
        x++;
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}