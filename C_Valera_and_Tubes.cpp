#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
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

int32_t main(){
    int n,m,k;
    cin>>n>>m>>k;
    int i=1,j=1,d=1;
    for(int kl=0;kl<k-1;kl++){
        cout<<2<<" ";
        cout<<i<<" "<<j<<" ";
        if(j==m && d==1){
            j=m;
            i+=1;
            d=-1;
        }
        else if(j==1 && d==-1){
            j=1;
            d=1;
            i++;
        }
        else{
            if(d==1){
                j++;
            }
            else{
                j-=1;
            }
        }
        cout<<i<<" "<<j<<"\n";
        if(j==m && d==1){
            j=m;
            i+=1;
            d=-1;
        }
        else if(j==1 && d==-1){
            j=1;
            d=1;
            i++;
        }
        else{
            if(d==1){
                j++;
            }
            else{
                j-=1;
            }
        }
    }
    //n->even hai last mai i==1 aur j==m hoga//n->odd hai toh last mai i==n aur j===m
    //cout<<i<<" "<<j;
    //cout<<d<<" "; 
    vector<pii> v;
    if(n%2==0){
        while(true){
            v.pb({i,j});
            if(i==n && j==1){
                break;
            }
            if(j==m && d==1){
                j=m;
                i+=1;
                d=-1;
            }
            else if(j==1 && d==-1){
                j=1;
                d=1;
                i++;
            }
            else{
                if(d==1){
                    j++;
                }
                else{
                    j-=1;
                }
            }
        }
    }
    else{
        while(true){
            v.pb({i,j});
            if(i==n && j==m){
                break;
            }
            if(j==m && d==1){
                j=m;
                i+=1;
                d=-1;
            }
            else if(j==1 && d==-1){
                j=1;
                d=1;
                i++;
            }
            else{
                if(d==1){
                    j++;
                }
                else{
                    j-=1;
                }
            }
        }
    }
    cout<<v.size()<<" ";
    for(auto i:v){
        cout<<i.ff<<" "<<i.ss<<" ";
    }
    cout<<"\n";
}