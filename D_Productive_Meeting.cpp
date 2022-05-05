#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <stack>
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
void solve(){
    priority_queue<pair<int,int>> pq;
    int n;
    cin>>n;
    int k;
    vector<pair<int,int>> v;
    for(int i = 1;i<=n;i++){
        cin >> k;
        if(k>0)pq.push({k,i});
    }
    while(!pq.empty()){
        if(pq.size() < 2){
            break;
        }
        pair<int,int> p1,p2;
        p1 = pq.top();
        pq.pop();
        p2 = pq.top();
        pq.pop();
        v.push_back({p1.second , p2.second});
        p1.first--;
        p2.first--;
        if(p1.first !=0){
            pq.push(p1);
        }
        if(p2.first != 0)
            pq.push(p2);
    }
    cout<<v.size()<<"\n";
    for(auto i:v){
        cout<<i.first<<" "<<i.second<<"\n";
    }
}
int32_t main(){
    FIO;
    int w;
    cin >> w;
    while(w--){
        solve();
    }
}