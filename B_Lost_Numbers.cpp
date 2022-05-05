#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
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
#define vip             vector<pair<int,double>>
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

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
 
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}
int32_t main(){
    int a[6]={4,8,15,16,23,42};
    int ans[7];
    cout<<"? "<<1<<" "<<1<<endl;
    int k;
    cin>>k;
    ans[1]=sqrt(k);
    cout<<"? "<<2<<" "<<2<<endl;
    cin>>k;
    ans[2]=sqrt(k);
    vi p;
    for(int i=0;i<6;i++){
        if(a[i]!=ans[1] && a[i]!=ans[2]){
            p.push_back(a[i]);
        }
    }
    cout<<"? "<<3<<" "<<4<<endl;
    int k1;
    cin>>k1;
    cout<<"? "<<4<<" "<<5<<endl;
    int k2;
    cin>>k2;
    int x1=-1,x2=-1;
    int y1=-1,y2=-1;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(p[i]*p[j]==k1){
                x1=p[i],x2=p[j];
                break;
            }
        }
        if(x1!=-1){
            break;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(p[i]*p[j]==k2){
                y1=p[i],y2=p[j];
                break;
            }
        }
        if(y1!=-1){
            break;
        }
    }
    if(x1==y1){
        ans[4]=x1;
        ans[3]=x2;
        ans[5]=y2;
    }
    else if(x1==y2){
        ans[4]=x1;
        ans[3]=x2;
        ans[5]=y1;
    }
    else if(x2==y1){
        ans[4]=x2;
        ans[3]=x1;
        ans[5]=y2;
    }
    else{
        ans[4]=x2;
        ans[3]=x1;
        ans[5]=y1;
    }
    for(int i=0;i<4;i++){
        if(p[i]!=x1 && p[i]!=x2 && p[i]!=y1 && p[i]!=y2){
            ans[6]=p[i];
            break;
        }
    }
    cout<<"! ";
    for(int i=1;i<=6;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
