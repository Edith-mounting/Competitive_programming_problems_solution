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
    int n,m;
    cin>>n>>m;//n->0,m->1;
    if(n>m+1){
        cout<<-1;
    }
    else if(n==m+1){
        for(int i=0;i<m;i++){
            cout<<"01";
        }
        cout<<"0";
    }
    else{
        bool b=true;
        string s="";
        while(m>n && (n!=0)){
            s+="110";
            m-=2;
            n-=1;
        }
        while(m>0 || n>0){
            if(m>0){
                s+='1';
                m--;
            }
            if(n>0){
                s+='0';
                n--;
            }
        }
        string k="";
        for(int i=0;i<s.length()-2;i++){
            k="";
            for(int j=i;j<i+3;j++){
                k+=s[j];
            }
            if(k=="111"){
                b=false;
                break;
            }
        }
        for(int i=0;i<s.length()-1;i++){
            k="";
            for(int j=i;j<i+2;j++){
                k+=s[j];
            }
            if(k=="00"){
                b=false;
                break;
            }
        }
        if(!b){
            cout<<-1;
        }
        else{
            cout<<s;
        }
    }
    cout<<"\n";
}