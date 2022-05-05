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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int w=1;
    //cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<char> v;
        int init=0;
        int i1=0,i2=n-1;
        for(int i=0;i<n;i++){
            if(i1>i2){
                break;
            }
            int q1=min(a[i1],a[i2]);
            if(q1>init){
                init=q1;
                if(a[i1]==q1){
                    i1++;
                    v.pb('L');
                }
                else{
                    i2--;
                    v.pb('R');
                }
            }
            else{
                int q2=max(a[i1],a[i2]);
                if(q2>init){
                    init=q2;
                    if(a[i1]==q2){
                        i1++;
                        v.pb('L');
                    }
                    else{
                        i2--;
                        v.pb('R');
                    }
                }
                else{
                    break;
                }
            }
        }
        cout<<v.size()<<"\n";
        for(char c:v){
            cout<<c;
        }
        cout<<"\n";
    }
}