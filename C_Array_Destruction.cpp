#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool>
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

int32_t main(){
    FIO;
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[2*n];
        for(int i=0;i<2*n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<"YES\n";
            cout<<(a[0]+a[1])<<"\n";
            cout<<a[0]<<" "<<a[1]<<"\n";
            continue;
        }
        n=2*n;
        sort(a,a+n);
        bool bl=false;
        for(int i=0;i<n-1;i++){
            vector<pii> v;
            v.pb({a[i],a[n-1]});
            int max_till=a[n-1];
            multiset<int> s;
            for(int j=0;j<i;j++){
                s.insert(a[j]);
            }
            for(int j=i+1;j<n-1;j++){
                s.insert(a[j]);
            }
            bool b=true;
            //cout<<i<<"\n";
            while(!s.empty()){
                multiset <int> :: iterator itr;
                itr=s.end();
                itr--;
                s.erase(s.find(*itr));
                int xl=max_till-(*itr);
                if(s.find(xl)!=s.end()){
                    //cout<<(*itr)<<" "<<xl<<" "<<s.count(3)<<"\n";
                    max_till=max(*itr,xl);
                    s.erase(s.find(xl));
                    v.pb({*itr,xl});
                }
                else{
                    b=false;
                    break;
                }
            }
            if(b){
                bl=true;
                cout<<"YES\n";
                cout<<(a[i]+a[n-1])<<"\n";
                for(auto j:v){
                    cout<<j.ff<<" "<<j.ss<<"\n";
                }
                break;
            }
        }
        if(!bl){
            cout<<"NO\n";
        }
        //cout<<"\n";
    }
}