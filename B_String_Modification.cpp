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
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<string> v;
        v.pb(s);
        for(int k=2;k<=n;k++){
            string sl="";
            if(k==2){
                for(int i=1;i<n;i++){
                    sl+=s[i];
                }
                sl+=s[0];
            }
            else{
                for(int i=k-1;i<n;i++){
                    sl+=s[i];
                }
                if(n%2==1){
                    if(k%2==1){
                        for(int i=k-2;i>=0;i--){
                            sl+=s[i];
                        }
                    }
                    else{
                        for(int i=0;i<k-1;i++){
                            sl+=s[i];
                        }
                    }
                }
                else{
                    if(k%2==1){
                        for(int i=0;i<k-1;i++){
                            sl+=s[i];
                        }
                    }
                    else{
                        for(int i=k-2;i>=0;i--){
                            sl+=s[i];
                        }
                    }
                }
            }
            v.pb(sl);
        }
        vector<string> vl;
        for(auto i:v){
            vl.pb(i);
        }
        sort(v.begin(),v.end());
        cout<<v[0]<<"\n";
        for(int i=0;i<n;i++){
            if(vl[i]==v[0]){
                cout<<i+1<<"\n";
                break;
            }
        }
    }
}