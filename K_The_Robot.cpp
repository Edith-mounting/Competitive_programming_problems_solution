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
pii f(pii a,char k){
    pii q;
    q.ff=a.ff,q.ss=a.ss;
    if(k=='R'){
        q.ff++;
    }
    else if(k=='L'){
        q.ff--;
    }
    else if(k=='D'){
        q.ss--;
    }
    else{
        q.ss++;
    }
    return q;
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        string s;
        cin>>s;
        int n=s.length();
        bool b=false;
        pii x;
        x.ff=0,x.ss=0;
        for(int i=0;i<n;i++){
            pii m=f(x,s[i]);
            x=m;
            pii q={0,0};
            for(int j=0;j<n;j++){
                pii l=f(q,s[j]);
                if(l!=x){
                    q=l;
                }
            }
            if(q.ff==0 && q.ss==0){
                b=true;
                break;
            }
        }
        if(b){
            cout<<x.ff<<" "<<x.ss;
        }
        else{
            cout<<0<<" "<<0;
        }
        cout<<"\n";
    }
}