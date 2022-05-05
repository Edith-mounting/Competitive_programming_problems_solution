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
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
pair<pair<int,int>,bool> slope(int x1,int y1,int x2,int y2){
    pii ans;
    bool k;
    int p1=(y2-y1);
    int q1=(x2-x1);
    if(q1==0){
        ans.ff=-1;
        ans.ss=-1;
        q1=1;
        if(p1>0){
            k=true;
        }
        else{
            k=false;
        }
    }
    else if(p1==0){
        ans.ff=0;
        ans.ss=0;
        p1=1;
        if(q1>0){
            k=true;
        }
        else{
            k=false;
        }
    }
    else{
        ans.ff=(p1/(__gcd(p1,q1)));
        ans.ss=(q1/(__gcd(p1,q1)));
        if(p1>0){
            if(q1>0){
                k=true;
            }
            else{
                k=false;
            }
        }
        else{
            if(q1>0){
                k=true;
            }
            else{
                k=false;
            }
        }
    }
    return {ans,k};
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        map<pair<pair<int,int>,bool>,int> mp;
        for(int i=0;i<n;i++){
            int x1,y1,u1,v1;
            cin>>x1>>y1>>u1>>v1;
            pair<pair<int,int>,bool> pq=slope(x1,y1,u1,v1);
            mp[pq]++;
        }
        /*for(auto i:mp){
            cout<<((i.ff).ff).ff<<" "<<((i.ff).ff).ss<<" "<<((i.ff).ss)<<" "<<i.ss<<"\n";
        }*/
        int ans=0;
        pii x;
        bool y;
        pair<pair<int,int>,bool> l;
        for(auto i:mp){
            x=(i.ff).ff;
            y=(i.ff).ss;
            l={x,true};
            if(y==true){
                l={x,false};
            }
            if(mp.find(l)!=mp.end()){
                ans+=((i.ss)*mp[l]);
            }
        }
        cout<<ans/2<<"\n";
    }
}