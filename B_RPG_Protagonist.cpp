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
int can_take(int s,int w,int counts,int countw,int p){
    if(s>w){
        return can_take(w,s,countw,counts,p);
    }
    if(s*counts>=p){
        return p/s;
    }
    else{
        return counts+min((p-s*counts)/w,countw);
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int p,f,counts,countw,s,w;
        cin>>p>>f>>counts>>countw>>s>>w;
        int best=0;
        for(int i=0;i<=counts;i++){
            if(i*s<=p){
                int j=min(countw,(p-i*s)/w);
                best=max(best,i+j+can_take(s,w,counts-i,countw-j,f));
            }
        }
        cout<<best<<"\n";
    }
}