#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
//#include <bits/stdc++.h>
#include <queue> 
#include <iomanip>
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
const double pi = acos(-1);
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
struct sk{
    int sum,number,index;
};
bool cmp(sk a,sk b){
    return a.sum>b.sum;
}
int32_t main(){
    int n;
    cin>>n;
    vector<sk> v(n);
    for(int i=0;i<n;i++){
        int x1,x2;
        cin>>x1>>x2;
        v[i].sum=x2;
        v[i].number=x1;
        v[i].index=i+1;
    }
    sort(v.begin(),v.end(),cmp);
    int ans1=0,ans2=0;
    int m;
    cin>>m;
    vector<pii> table(m);
    for(int i=0;i<m;i++){
        cin>>table[i].ff;
        table[i].ss=i+1;
    }
    vector<pii> count;
    sort(table.begin(),table.end());
    for(int i=0;i<n;i++){
        for(int j=0;j<table.size();j++){
            if(table[j].ff>=v[i].number){
                ans1++;
                ans2+=v[i].sum;
                count.pb({v[i].index,table[j].ss});
                table[j].ff=0;
                break;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<"\n";
    for(auto i:count){
        cout<<i.ff<<" "<<i.ss<<"\n";
    }
}