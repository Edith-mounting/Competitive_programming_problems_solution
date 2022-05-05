#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        vector<int> d(2*n);
        bool b=true;
        for(int i=0;i<2*n;i++){
            int k;
            cin>>k;
            d[i]=k;
            if(k%2==1){
                b=false;
            }
        }
        vi v(n);
        vi a(n,0);
        int sum=0;
        if(!b){
            cout<<"NO"<<"\n";
        }
        else{
            if(n==1){
                if(d[0]==d[1]){
                    if(d[0]%2==0){
                        cout<<"YES"<<"\n";
                    }
                    else{
                        cout<<"NO"<<"\n";
                    }
                }
                else{
                    cout<<"NO"<<"\n";
                }
                b=false;
            }
            if(b){
            sort(d.begin(),d.end());
            for(int i=0;i<n && b;i++){
                if(d[i*2]!=d[i*2+1]){
                    cout<<"NO"<<"\n";
                    b=false;
                }
                v[i]=d[i*2];
            }}
            if(b){
                for(int i=1;i<n;i++){
                    if(v[i]==v[i-1]){
                        cout<<"NO"<<"\n";
                        b=false;
                    }
                }
            }
            if(b){      
                for(int i=n-1;i>=0 && b;i--){
                    if(v[i]<sum){
                        cout<<"NO"<<"\n";
                        b=false;
                    }
                    if((v[i]-sum)%(2*(i+1))==0){
                        a[i]=(v[i]-sum)/(2*(i+1));
                        if(a[i]==0){
                            cout<<"NO"<<"\n";
                            b=false;
                        }
                    }
                    else{
                        cout<<"NO"<<"\n";
                        b=false;
                    }
                    sum+=2*a[i];
                }
                if(b){
                    cout<<"YES"<<"\n";
                }
            }
        }
    }
}