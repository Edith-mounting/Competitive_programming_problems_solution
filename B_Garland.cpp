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
    string s1,s2;
    cin>>s1>>s2;
    int a[26]={},b[26]={};
    for(int i=0;i<s1.length();i++){
        a[s1[i]-'a']++;
    }
    for(int i=0;i<s2.length();i++){
        b[s2[i]-'a']++;
    }
    int count=0;
    bool bl=true;
    for(int i=0;i<26;i++){
        if(b[i]>0){
            if(a[i]==0){
                bl=false;
                break;
            }
            else{
                count+=min(a[i],b[i]);
            }
        }
    }
    if(!bl){
        cout<<-1;
    }
    else{
        cout<<count;
    }
    cout<<"\n";
}