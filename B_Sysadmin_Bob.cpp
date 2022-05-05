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
    string s;
    cin>>s;
    int n=s.length();
    vector<int> v;
    //string k="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='@'){
            v.pb(i);
        }
    }
    bool b=true;
    if(v.size()==0){
        b=false;
    }
    if(b){
    if(v[0]==0){
        b=false;
    }
    else if(v[v.size()-1]==s.length()-1){
        b=false;
    }
    for(int i=1;i<v.size();i++){
        if(v[i]<=v[i-1]+2){
            b=false;
            break;
        }
    }}
    if(b){
        string k="";
        int p=0;
        int i;
        for(i=0;i<n;){
            if(i==v[p]){
                if(p==v.size()-1){
                    k+=s[i];
                    k+=s[i+1];
                    i+=2;
                    break;
                }
                else{
                    k+=s[i];
                    k+=s[i+1];
                    k+=',';
                    i+=2;
                }
                p++;
            }
            else{
                k+=s[i];
                i++;
            }
        }
        while(i<n){
            k+=s[i];
            i++;
        }
        cout<<k;
    }
    else{
        cout<<"No solution";
    }
    cout<<"\n";
}