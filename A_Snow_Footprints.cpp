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
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i1=-1,i2,c=0;
    bool b=false;
    for(int i=0;i<n;i++){
        if(s[i]=='R' && i1==-1){
            i1=i+1;
        }
        else if(s[i]=='R' && i1!=-1){
            c++;
        }
        else if(s[i]=='L'){
            b=true;
        }
        else{
            continue;
        }
    }
    if(i1!=-1 && b){
        cout<<i1<<" "<<i1+c<<"\n";
    }
    else if(i1!=-1 && !b){
        cout<<i1<<" "<<i1+c+1<<"\n";
    }
    else{
        int i1=-1,i2,c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L' && i1==-1){
                i1=i+1;
            }
            else if(s[i]=='L' && i1!=-1){
                c++;
            }   
            else{
                continue;
            }
        }
        cout<<i1+c<<" "<<i1-1<<"\n";
    }
}
int32_t main(){
    FIO;
    solve();
}