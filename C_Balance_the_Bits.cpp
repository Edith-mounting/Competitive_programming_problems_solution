#include <iostream>
#include <algorithm>
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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int x1=0,x2=0;
        bool bl=true;
        if(!(s[0]==s[n-1] && s[0]=='1')){
            bl=false;
        }
        if(!bl){
            cout<<"NO"<<"\n";
            continue;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                x1++;
            }
            else{
                x2++;
            }
        }
        if(x1%2==1 || x2%2==1){
            bl=false;
        }
        if(!bl){
            cout<<"NO"<<"\n";
            continue;
        }
        int k=0,k1=0;
        string s1="",s2="";
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
            if(k< x1/2 ){
                s1+="(";
                s2+="(";
                k++;
            }
            else{
                s1+=")";
                s2+=")";
                k++;
            }}
            else{
            if(k1%2==0){
                s1+=")";
                s2+="(";
                k1++;
            }
            else{
                s2+=")";
                s1+="(";
                k1++;
            }}
        }
        cout<<"YES"<<"\n";
        cout<<s1<<"\n";
        cout<<s2<<"\n";
    }
}