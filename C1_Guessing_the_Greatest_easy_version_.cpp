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
int lq(int l,int r){
    cout<<"?"<<" "<<l<<" "<<r<<endl;
    cout<<endl;
    int kl;
    cin>>kl;
    return kl;
}
int32_t main(){
    int n;
    cin>>n;
    int ans=0;
    int p=1,q=n;
    cout<<"?"<<" "<<p<<" "<<q<<endl;
    cout<<endl;
    int smax;
    cin>>smax;
    if(n==2){
        if(smax==1){
            ans=2;
        }
        else{
            ans=1;
        }
    }
    else{
    if(lq(p,smax)==smax){
        int mid;
        p=1;
        q=smax;
        mid=(p+q)/2;
        while(p<q){
            if(q-p==1){
                if(smax==q){
                    mid=p;
                    break;
                }
                if(lq(q,smax)==smax){
                    mid=q;
                }
                else{
                    mid=p;
                }
                break;
            }
            else if(p==q){
                mid= (p+q)/2;
                break;
            }
            mid=(p+q)/2;
            if(lq(mid,smax)==smax){
                p=mid;
            }
            else{
                q=mid;
            }
        }
        ans=mid;
    }
    else{
        int mid;
        p=smax;
        q=n;
        mid=(p+q)/2;
        while(p<q){
            if(q-p==1){
                if(smax==p){
                    mid=q;
                    break;
                }
                if(lq(smax,p)==smax){
                    mid=p;
                }
                else{
                    mid=q;
                }
                break;
            }
            else if(p==q){
                mid=p;
                break;
            }
            mid=(p+q)/2;
            if(lq(smax,mid)==smax){
                q=mid;
            }
            else{
                p=mid;
            }
        }
        ans=mid;
    }}
    cout<<"!"<<" "<<ans<<endl;
    cout<<endl;
}