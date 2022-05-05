#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
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
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    bool b=false;
    for(int i=1;i<n;i++){
        if(v[i]!=v[i-1]){
            b=true;
            break;
        }
    }
    if(n==1){
        b=false;
    }
    if(b){
        sort(v.begin(),v.end());
        int index;
        vector<int>::iterator l,u;
        for(int i=0;i<n;i++){
            l=lower_bound(v.begin(), v.end(),v[i]+1);
            //cout<<(l - v.begin())<<"\n";
            int k=l-v.begin();
            if((n-k)<=(i+1)){
                index=i;
                break;
            }
        }
        //cout<<index<<"\n";
        vi ans1,ans2,ans;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans1.pb(v[n-i/2-1]);
            }
            else{
                ans2.pb(v[i/2]);
            }
        }
        reverse(ans1.begin(),ans1.end());
        int i=0,j=0;
        while(i<ans1.size() && j<ans2.size()){
            ans.pb(ans1[i]);
            ans.pb(ans2[j]);
            i++;j++;
        }
        while(i<ans1.size()){
            ans.pb(ans1[i]);
            i++;
        }
        int count=0;
        for(i=1;i<n-(1-n%2);i+=2){
            if(ans[i]<ans[i-1] && ans[i]<ans[i+1]){
                count++;
            }
        }
        cout<<count<<"\n";
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<0<<"\n";
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}