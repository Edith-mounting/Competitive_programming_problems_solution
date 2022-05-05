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
int absk(int x){
    if(x<0){
        return -x;
    }
    return x;
}
const int N = 10000000+20;
int lp[N+1];
vector<int> pr;

int32_t main(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    vector<int> v;
    for(int i=2;i<N;i++){
        if(lp[i]==i){
            v.pb(i);
        }
    }
    int a[11]={};
    a[1]=7;
    int k=1;
    for(int i=4;i<v.size();i++){
        int q=v[i];
        int x=0;
        while(q>0){
            x++;
            q/=10;
        }
        if(x>k){
            a[x]=v[i];
            k=x;
        }
    }
    for(int i=2;i<11;i++){
        a[i]=a[i]*7;
    }
    a[9]=(100000000)*7;
    int b[10];
    b[0]=1;
    for(int i=1;i<9;i++){
        b[i]=b[i-1]*7;
    }
    int w;
    cin>>w; 
    while(w--){
        int a1,b1,c;
        cin>>a1>>b1>>c;
        vector<int> vl;
        int x1=-1,y1=-1;
        cout<<x1<<" "<<y1<<"\n";
        cout<<__gcd(x1,y1)<<"\n";
    }
}