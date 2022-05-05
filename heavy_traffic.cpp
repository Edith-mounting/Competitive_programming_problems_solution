#include <iostream>
#include <algorithm>
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
string solve(){
    int m,n;
    cin>>m>>n;
    int p[m];
    for(int i=0;i<m;i++){
        cin>>p[i];
    }
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].ff;
    }
    for(int j=0;j<n;j++){
        cin>>v[j].ss;
    }
    vector<pair<vip,vip>> block(m-1);
    sort(v.begin(),v.end());
    bool b=true;
    int start=0;
    for(int i=0;i<n;i++){
        while(v[i].ff>p[start]){
            start++;
        }
        if(v[i].ff == p[start]){
            continue;
        }
        else{
            if(v[i].ss>0){
                double k1=double(p[start]-v[i].ff)/double(v[i].ss);
                block[start-1].ff.pb({v[i].ff,k1});
            }
            else{
                double k1=double(v[i].ff-p[start-1])/double(absk(v[i].ss));
                block[start-1].ss.pb({v[i].ff,k1});
            }
        }
    }
    for(int i=0;i<m-1;i++){
        sort(block[i].ff.begin(),block[i].ff.end());
        sort(block[i].ss.begin(),block[i].ss.end());
    }
    for(int i=0;i<m-1;i++){
        if(block[i].ff.size()>1){
            for(int j=0; j<block[i].ff.size()-1 ;j++){
                if((block[i].ff)[j].ss - (block[i].ff)[j+1].ss< 1e-7){
                    b=false;
                    break;
                }
            }
        }
        if(block[i].ss.size()>1){
            for(int j=0; j<block[i].ss.size()-1 ;j++){
                if((block[i].ss)[j].ss - (block[i].ss)[j+1].ss > 1e-7){
                    b=false;
                    break;
                }
            }
        }
        if(!b){
            break;
        }
    }
    for(int i=0;i<m-1;i++){
        if(block[i].ff.size()==0 || block[i].ss.size()==0){
            continue;
        }
        else{
            int k1=(block[i].ss)[block[i].ss.size()-1].ff;
            if(k1>block[i].ff[0].ff){
                b=false;
                break;
            }
        }
    }
    if(b){
        return "YES";
    }
    return "NO";
}
int32_t main(){
    FIO;
    int w;
    cin>>w;
    while(w--){
        cout<<solve()<<"\n";
    }
}