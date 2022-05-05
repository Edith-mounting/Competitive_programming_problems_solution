#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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

int32_t main() 
{
    int w;
    cin>>w;
    while (w--)
    {
        string s;
        cin>>s;
        int x,n;
        cin>>x;
        n=s.length();
        vi v(n,1);
        bool bl=true;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(i-x>=0){
                    v[i-x]=0;
                }
                if(i+x<=n-1){
                    v[i+x]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(i-x>=0 && i+x<n){
                    if(v[i-x]==1 || v[i+x]==1){
                        continue;
                    }
                    else{
                        bl=false;
                        break;
                    }
                }
                else if(i-x>=0){
                    if(v[i-x]!=1){
                        bl=false;
                        break;
                    }
                }
                else if(i+x<n){
                    if(v[i+x]!=1){
                        bl=false;
                        break;
                    }
                }
            }
        }
        if(!bl){
            cout<<-1;
        }
        else{
            for(auto i:v){
                cout<<i;
            }
        }
        cout<<"\n";
    }
}