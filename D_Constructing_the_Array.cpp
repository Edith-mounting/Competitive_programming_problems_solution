#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
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
#define PI              3.14159265
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
vi a;
int x;
bool comp(pii k1,pii k2){
    int a1=(k1.ss-k1.ff);
    int a2=(k2.ss-k2.ff);
    if(a1==a2){
        return k1.ff < k2.ff;
    }
    return a1>a2;
}
void f(int left,int right){
    queue<pii> q;
    q.push({left,right});
    while(!q.empty()){
        vector<pii> v;
        while(!q.empty()){
            int l=q.front().ff,r=q.front().ss;
            q.pop();
            v.pb({l,r});
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<v.size();i++)
        {
            int l=v[i].ff,r=v[i].ss;
            cout<<l<<" "<<r<<"\n";
            if(l<=r){
                int mid;
                if(r==l){
                    mid=l;
                }
                else if((r-l+1)%2==1){
                    mid=(r+l)/2;
                }
                else{
                    mid=(r+l-1)/2;
                }
                a[mid]=x;
                x++;
                if((mid-l)>=(r-mid)){
                    if(l<=mid-1){
                    q.push({l,mid-1});}
                    if(mid+1<=r){
                    q.push({mid+1,r});}
                }
                else{
                    if(mid+1<=r){
                    q.push({mid+1,r});}
                    if(l<=mid-1){
                    q.push({l,mid-1});}
                }
            }
        }
    }
}
int32_t main(){
    int wl;
    cin>>wl;
    while(wl--){
        x=1;
        int n;
        cin>>n;
        a.clear();
        a.resize(n+1);
        f(1,n);
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        //cout<<"\n";
    }
}