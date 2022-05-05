#include <iostream>
#include <algorithm>
#include <iomanip>
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

int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        return powd(x,y/2)*powd(x,y/2);
    }
    else{
        int t=powd(x,y/2);
        return (x*t*t);
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int W,H;
        cin>>W>>H;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int w,h;
        cin>>w>>h;
        double ans=0.000000000;
        if(x1>=w){
            cout<<ps(ans,10)<<"\n";
            continue;
        }
        else if(y1>=h){
            cout<<ps(ans,10)<<"\n";
            continue;
        }
        else if((H-y2)>=h){
            cout<<ps(ans,10)<<"\n";
            continue;
        }
        else if((W-x2)>=w){
            cout<<ps(ans,10)<<"\n";
            continue;
        }
        bool bl=false;
        if((x2-x1)+w<=W || (y2-y1)+h<=H){
            bl=true;
        }
        if(!bl){
            cout<<-1<<"\n";
            continue;
        }
        ans=(double)inf;
        if(w+(x2-x1)<=W){
            ans=min(ans,(double)(w-x1));
            ans=min(ans,(double)(x2-W+w));
        }
        if(h+(y2-y1)<=H){
            ans=min(ans,(double)(h-y1));
            ans=min(ans,(double)(y2-H+h));
        }
        cout<<ps(ans,10)<<"\n";
    }
}