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
#define mod             998244353
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

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n,l,r,s,sl;
        cin>>n>>l>>r>>s;
        sl=s;
        int i1=l;
        vector<int> ans(n+1,0);
        vector<bool> vis(n+1,false);
        for(int i=n;i>=1;i--){
            if(i<=s){
                ans[i1]=i;
                vis[i]=true;
                i1++;
                s=s-i;
                if(i1>r){
                    break;
                }
            }
        }
        vector<int> v;
        for(int i=1;i<n+1;i++){
            if(!vis[i]){
                v.pb(i);
            }
        }
        i1=0;
        for(int i=1;i<n+1;i++){
            if(ans[i]==0){
                if(i1<v.size()){
                    ans[i]=v[i1];
                    i1++;
                }
            }
        }
        if(s!=0){
            cout<<-1<<"\n";
            continue;
        }
        int sum1=0;
        for(int i=l;i<=r;i++){
            sum1+=ans[i];
        }
        if(sum1!=sl){
            cout<<-1<<"\n";
            for(int i=1;i<n+1;i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
            continue;
        }
        set<int> st;
        for(int i=1;i<n+1;i++){
            st.insert(ans[i]);
        }
        if(st.size()!=n){
            //cout<<"YES";
            cout<<-1<<"\n";
        }
        else{
            for(int i=1;i<n+1;i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
    }
}