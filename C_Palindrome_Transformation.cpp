#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
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
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    int count=0;
    p--;
    if(p< n/2 +n%2){
        int leftindex=p,rightindex=p;
        for(int i=p;i>=0;i--){
            if(s[i]!=s[n-i-1]){
                leftindex=i;
            }
        }
        for(int i=p;i<n/2 +n%2;i++){
            if(s[i]!=s[n-i-1]){
                rightindex=i;
            }
        }
        //cout<<leftindex<<" "<<rightindex<<"\n";
        count+=2*min(p-leftindex,rightindex-p) +max(p-leftindex,rightindex-p);
        //cout<<count<<"\n";
        for(int i=0;i<n/2 +n%2;i++){
            if((int)(s[i]-'a')>(int)(s[n-i-1]-'a')){
                //cout<<min((int)(s[i]-s[n-i-1]),26-(int)(s[i]-'a') +(int)(s[n-i-1]-'a') +1)<<"\n";
                count+=min((int)(s[i]-s[n-i-1]),26-(int)(s[i]-'a') +(int)(s[n-i-1]-'a'));
            }
            else{
                //cout<<min((int)(s[n-i-1]-s[i]),26-(int)(s[n-i-1]-'a') +(int)(s[i]-'a') +1)<<"\n";
                count+=min((int)(s[n-i-1]-s[i]),26-(int)(s[n-i-1]-'a') +(int)(s[i]-'a'));
                //cout<<26-(int)(s[n-i-1]-'a'+1) +(int)(s[i]-'a') +1<<"\n";
            }
        }
    }
    else{
        int leftindex=p,rightindex=p;
        for(int i=p;i>=n/2 +n%2;i--){
            if(s[i]!=s[n-i-1]){
                leftindex=i;
            }
        }
        for(int i=p;i<n;i++){
            if(s[i]!=s[n-i-1]){
                rightindex=i;
            }
        }
        count+=2*min(p-leftindex,rightindex-p) +max(p-leftindex,rightindex-p);
        for(int i=n/2 +n%2;i<n;i++){
            if((int)s[i]>(int)s[n-i-1]){
                count+=min((int)(s[i]-s[n-i-1]),26-(int)(s[i]-'a') +(int)(s[n-i-1]-'a'));
            }
            else{
                count+=min((int)(s[n-i-1]-s[i]),26-(int)(s[n-i-1]-'a') +(int)(s[i]-'a'));
            }
        }
    }
    cout<<count;
    cout<<"\n";
}