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
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int c1=0,c2=0,c3=0;
    for(int i=0;i<2*n;i++){
        if(s1[i]==s2[i] && s1[i]=='1'){
            c1++;
        }
        else{
            if(s1[i]=='1'){
                c2++;
            }
            if(s2[i]=='1'){
                c3++;
            }
        }    
    }
    string ans;
    c2+= c1%2;
    if(c2>c3){
        ans="First";
    }
    else{
        if((c2==c3) || (c2+1==c3)){
            ans="Draw";
        }
        else{
            ans="Second";
        }
    }
    cout<<ans;
    cout<<"\n";
}