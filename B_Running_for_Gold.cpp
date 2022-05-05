#include <iostream>
#include <algorithm>
#include <map>
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

struct help
{
    int x1,x2,x3,x4,x5,i1;
};

bool comp(help x,help y){
    int count1=0;
    if(x.x1>y.x1){
        count1++;
    }
    if(x.x2>y.x2){
        count1++;
    }
    if(x.x3>y.x3){
        count1++;
    }
    if(x.x4>y.x4){
        count1++;
    }
    if(x.x5>y.x5){
        count1++;
    }
    if(count1>=3){
        return false;
    }
    else{
        return true;
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        help a[n];
        for(int i=0;i<n;i++){
            int a1,a2,a3,a4,a5;
            cin>>a1>>a2>>a3>>a4>>a5;
            a[i].x1=a1;
            a[i].x2=a2;
            a[i].x3=a3;
            a[i].x4=a4;
            a[i].x5=a5;
            a[i].i1=i+1;
        }
        sort(a,a+n,comp);
        int ans=a[0].i1;
        for(int i=1;i<n;i++){
            int count1=0;
                if(a[0].x1<a[i].x1){
                    count1++;
                }
                if(a[0].x2<a[i].x2){
                    count1++;
                }
                if(a[0].x3<a[i].x3){
                    count1++;
                }
                if(a[0].x4<a[i].x4){
                    count1++;
                }
                if(a[0].x5<a[i].x5){
                    count1++;
                }
                if(count1<3){
                    ans=-1;
                    break;
                }
        }
        cout<<ans<<"\n";
    }
}