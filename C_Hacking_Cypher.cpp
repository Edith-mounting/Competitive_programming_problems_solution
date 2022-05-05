#include <iostream>
#include <algorithm>
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
//#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int powd(int x,int y,int mod){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2,mod)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2,mod)%mod;
        return (((x)%mod)*(t*t)%mod)%mod;
    }
}
int32_t main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<int> res(n,0);
    vector<int> resb(n+1,0);
    int a,b;
    cin>>a>>b;
    for(int i=n-1;i>=0;i--){
        resb[i]=(((s[i]-'0')*(powd(10,n-i-1,b)))%b +resb[i+1])%b;
    }
    bool bl=false;
    res[0]=(s[0]-'0')%a;
    for(int i=1;i<n;i++){
        res[i]=(res[i-1]*10 +(s[i]-'0'))%a;
    }
    int k=-1;
    for(int i=0;i<n;i++){
        if((s[i]-'0')>0){
            k=i-1;
            break;
        }
    }
    //cout<<k<<"\n";
    int ans;
    for(int i=0;i<n-1;i++){
        if(res[i]==0 && i>k){
            if(resb[i+1]==0){
                //cout<<"YES";
                bl=true;
                ans=i;
                break;
            }
        }
    }
    /*for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<resb[i]<<" ";
    }*/
    if(bl){
        string s1="",s2="";
        int i;
        for(i=0;i<=ans;i++){
            s1+=s[i];
        }
        for(i=ans+1;;i++){
            if(s[i]!='0'){
                break;
            }
            else{
                s1+=s[i];
            }
        }
        for(int j=i;j<n;j++){
            s2+=s[j];
        }
        if(s1.length()==0 || s2.length()==0){
            cout<<"NO"<<"\n";
        }
        else{
        cout<<"YES"<<"\n";
        cout<<s1<<"\n";
        cout<<s2<<"\n";}
    }
    else{
        cout<<"NO"<<"\n";
    }
}