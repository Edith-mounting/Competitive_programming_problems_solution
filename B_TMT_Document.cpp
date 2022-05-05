#include <iostream>
#include <algorithm>
#include <cmath>
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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        pii left[n]={};
        if(s[0]=='M'){
            cout<<"NO"<<"\n";
            continue;
        }
        if(s[n-1]=='M'){
            cout<<"NO"<<"\n";
            continue;
        }
        left[0].ff=1;
        left[0].ss=0;
        bool bl=true;
        for(int i=1;i<n;i++){
            if(s[i]=='M'){
                left[i].ff=left[i-1].ff;
                left[i].ss=left[i-1].ss+1;
                if(left[i].ff<left[i].ss){
                    bl=false;
                }
            }
            else{
                left[i].ff=left[i-1].ff+1;
                left[i].ss=left[i-1].ss;
            }
        }
        if(left[n-1].ff!=(left[n-1].ss)*2){
            bl=false;
        }
        pii right[n]={};
        right[n-1].ff=1;
        right[n-1].ss=0;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='M'){
                right[i].ff=right[i+1].ff;
                right[i].ss=right[i+1].ss+1;
                if(right[i].ff<right[i].ss){
                    bl=false;
                }
            }
            else{
                right[i].ff=right[i+1].ff+1;
                right[i].ss=right[i+1].ss;
            }
        }
        if(right[0].ff!=(right[0].ss)*2){
            bl=false;
        }
        if(bl){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }
}