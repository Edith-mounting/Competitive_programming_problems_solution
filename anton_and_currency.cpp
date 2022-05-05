#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve(){
    string s;
    cin>>s;
    int mini=inf,index;
    bool b=false;
    int x1=(s[s.length()-1]-'0'); 
    for(int i=0;i<s.length();i++){
        if((s[i]-'0')%2==0){
            b=true;
            int x2=(s[i]-'0');
            if(x1>x2){
                index=i;
                break;
            }
            else{
                index=i;
            }
        }
    }
    if(!b){
        cout<<-1;
    }
    else{
        for(int i=0;i<s.length();i++){
            if(i==index){
                cout<<s[s.length()-1];
            }
            else if(i==s.length()-1){
                cout<<s[index];
            }
            else{
                cout<<s[i];
            }
        }

    }
    cout<<"\n";
}
int32_t main()
{
    int w=1;
    while(w--){
        solve();
    }
}