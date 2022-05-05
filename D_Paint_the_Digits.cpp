#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main() 
{   
    FIO;
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        vi s(n);
        int maxi[n]={};
        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            s[i]=(int)(c-'0');
        }
        maxi[0]=s[0];
        for(int i=1;i<n;i++){
            maxi[i]=max(s[i],maxi[i-1]);
        }
        vi ans(n,0);
        vi v1,v2;
        int ma=0;
        for(int i=n-1;i>=0;i--){
            if(maxi[i]!=s[i]){
                ma=max(ma,s[i]);
            }
        }
        for(int i=0;i<n;i++){
            if((maxi[i]==s[i]) && (s[i]>=ma)){
                v1.pb(s[i]);
                ans[i]=2;
            }
            else{
                v2.pb(s[i]);
                ans[i]=1;
            }
        }
        bool bl=true;
        for(int i=1;i<v2.size();i++){
            if(v2[i]<v2[i-1]){
                bl=false;
                break;
            }
        }
        if(!bl){
            cout<<"-";
        }
        else{
            for(auto i:ans){
                cout<<i;
            }
        }
        cout<<"\n";
    }
}