#include<iostream>
#include <vector>
#include <set>
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



int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int k,x;
        cin>>k>>x;
        int ans=0;
        if(k>=x){
            ans=2*k-1;
        }
        else{
            vector<int> v;
            int x1=x;
            for(int i=2;i*i<=x1;i++){
                if(x1%i==0){
                    while(x1%i==0){
                        v.push_back(i);
                        x1=x1/i;
                    }
                }
            }
            if(x1>1){
                v.push_back(x1);
            }
            if(k>=v.size()){
                for(int i=0;i<v.size();i++){
                    ans+=v[i];
                }
                ans+=k-v.size();
            }
            else{
                int kl=v.size()-k+1;
                int xm=1;
                for(int i=0;i<kl;i++){
                    xm=xm*v[i];
                }
                ans+=xm;
                for(int i=kl;i<v.size();i++){
                    ans+=v[i];
                }
            }
        }
        cout<<ans<<"\n";
    }
}