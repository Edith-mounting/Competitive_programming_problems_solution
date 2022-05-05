#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return ((t*t)*x);
    }
}
struct help{
    int i1,x,y,z;
};
bool comp(help a,help b){
    if(a.x != b.x){
        return a.x<b.x;
    }
    else{
        if(a.y != b.y){
            return a.y<b.y;
        }
        else{
            return a.z<b.z;
        }
    }
}
int32_t main()
{
	FIO;
    int n;
    cin>>n;
    vector<help> v(n);
    for(int i=0;i<n;i++){
        int k1,k2,k3;
        cin>>k1>>k2>>k3;
        v[i].i1=i+1;
        v[i].x=k1;
        v[i].y=k2;
        v[i].z=k3;
    }
    while(!v.empty()){
        sort(v.begin(),v.end(),comp);
        int x1=v.back().x;
        int y1=v.back().y;
        int z1=v.back().z;
        int pos=v.back().i1;
        v.pop_back();
        int ind=0;
        int dis=inf;
        for(int i=0;i<v.size();i++){
            int dist=absk(v[i].x-x1);
            dist+=absk(v[i].y-y1);
            dist+=absk(v[i].z-z1);
            if(dist<dis){
                dis=dist;
                ind=i;
            }
        }
        cout<<pos<<" "<<v[ind].i1<<"\n";
        v.erase(v.begin()+ind);
    }
}
