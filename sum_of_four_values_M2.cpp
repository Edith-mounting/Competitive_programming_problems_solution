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
//#define int             long long
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
vector<pii> v;
vector<pair<int,pair<int,int>>> v1;
bool cmp1(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    return a.ff<b.ff;
}
bool cmp(pii a,pii b){
    return a.ff<b.ff;
}
int binary(int l,int r,int k){
    int mid;
    while(l<=r){
        mid=(r+l)/2;
        if(v[mid].ff==k){
            return v[mid].ss;
        }
        else if(v[mid].ff>k){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
int32_t main(){
    int n,x;
    cin>>n>>x;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i].ff;
        v[i].ss=i+1;
    }
    sort(v.begin(),v.end(),cmp);
    if(n<=3){
        cout<<"IMPOSSIBLE";
    }
    else{
        bool b=false;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                v1.pb({v[i].ff+v[j].ff,{v[i].ss,v[j].ss}});
            }
        }
        /*for(auto i:v1){
            cout<<i.ff<<"\n";
        }*/
        sort(v1.begin(),v1.end(),cmp1);
        //cout<<v1.size()<<" ";
        int l=0;
        int r=(n*(n-1)/2) -1;
        
        while(l<r){
            if(v1[l].ff+v1[r].ff==x){
                if((v1[l].ss).ff==(v1[r].ss).ff || (v1[l].ss).ff==(v1[r].ss).ss 
                || (v1[l].ss).ss==(v1[r].ss).ff || (v1[l].ss).ss==(v1[r].ss).ss){
                    //cout<<(v1[l].ss).ff<<" "<<(v1[l].ss).ss<<" "<<(v1[r].ss).ff<<" "<<(v1[r].ss).ss<<"\n";
                    r--;
                }
                else{
                    vi ans;
                    ans.pb((v1[l].ss).ff);
                    ans.pb((v1[l].ss).ss);
                    ans.pb((v1[r].ss).ff);
                    ans.pb((v1[r].ss).ss);
                    sort(ans.begin(),ans.end());
                    for(auto i:ans){
                        cout<<i<<" ";
                    }
                    b=true;
                    break;
                }
            }
            else if(v1[l].ff+v1[r].ff<x){
                l++;
            }
            else{
                r--;
            }
        }
        if(!b){
            cout<<"IMPOSSIBLE";
        }
    }
    cout<<"\n";
}