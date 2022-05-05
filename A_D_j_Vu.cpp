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
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        bool b=true;
        int i1;
        for(int i=0;i<n;i++){
            if(s[i]!='a'){
                i1=i;
                b=false;
                break;
            }
        }
        if(b){
            cout<<"NO"<<"\n";
            continue;
        }
        cout<<"YES"<<"\n";
        b=true;
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                b=false;
            }
        }
        if(b){
            cout<<'a'<<s<<"\n";
        }
        else{
            for(int i=0;i<n;i++){
                cout<<s[i];
                if(i==n/2 -1){
                    cout<<'a';
                }
            }
            cout<<"\n";
        }
    }
}