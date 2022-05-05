#include <iostream>
#include <iomanip>
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
#define PI              3.14159265
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int32_t main(){
    int wl;
    cin>>wl;
    while(wl--){
        string s;
        cin>>s;
        int n=s.length();
        int x1=0;
        pii cur={0,0};
        map<pair<pii,pii>,bool> mp;
        //mp[cur]=true;
        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                pii x={cur.ff,cur.ss+1};
                if((mp.find({cur,x})==mp.end()) && (mp.find({x,cur})==mp.end())){
                    mp[{cur,x}]=true;
                    mp[{x,cur}]=true;
                    cur=x;
                    x1+=5;
                }
                else{
                    cur=x;
                    x1+=1;
                }
            }
            else if(s[i]=='S'){
                pii x={cur.ff,cur.ss-1};
                if((mp.find({cur,x})==mp.end()) && (mp.find({x,cur})==mp.end())){
                    mp[{cur,x}]=true;
                    mp[{x,cur}]=true;
                    cur=x;
                    x1+=5;
                }
                else{
                    cur=x;
                    x1+=1;
                }
            }
            else if(s[i]=='E'){
                pii x={cur.ff+1,cur.ss};
                if((mp.find({cur,x})==mp.end()) && (mp.find({x,cur})==mp.end())){
                    mp[{cur,x}]=true;
                    mp[{x,cur}]=true;
                    cur=x;
                    x1+=5;
                }
                else{
                    cur=x;
                    x1+=1;
                }
            }
            else{
                pii x={cur.ff-1,cur.ss};
                if((mp.find({cur,x})==mp.end()) && (mp.find({x,cur})==mp.end())){
                    mp[{cur,x}]=true;
                    mp[{x,cur}]=true;
                    cur=x;
                    x1+=5;
                }
                else{
                    cur=x;
                    x1+=1;
                }
            }
        }
        cout<<x1<<"\n";
    }
}