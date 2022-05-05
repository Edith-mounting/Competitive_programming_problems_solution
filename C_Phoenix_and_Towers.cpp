#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main() 
{   
    int w;
    cin>>w;
    while(w--){
        int n,x,m;
        cin>>n>>m>>x;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vi ans(n,0);
        priority_queue<pii> pq;
        for(int i=0;i<m;i++){
            pq.push({0,i});
        }
        for(int i=0;i<n;i++){
            int k1=pq.top().ff,k2=pq.top().ss;
            k1-=a[i];
            pq.pop();
            pq.push({k1,k2});
            ans[i]=k2;
        }
        if(m==1){
            cout<<"YES\n";
            for(int i=0;i<n;i++){
                cout<<1<<" ";
            }
            continue;
        }
        else{
            int prev=pq.top().ff;
            pq.pop();
            bool bl=true;
            while(!pq.empty()){
                if(absk(pq.top().ff - prev)>x){
                    bl=false;
                    break;
                }
                else{
                    prev=pq.top().ff;
                    pq.pop();
                }
            }
            if(bl){
                cout<<"YES\n";
                for(int i:ans){
                    cout<<i+1<<" ";
                }
                cout<<"\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
}