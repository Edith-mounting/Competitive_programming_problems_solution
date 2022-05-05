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
    string s;
    cin>>s;
    string sl="";
    sl+=s[0];
    for(int i=1;i<n;i++){
        if(sl[i-1]==s[i]){
            if(i<n-1){
                if(s[i+1]==s[i]){
                    if(s[i]=='R'){
                        sl+='B';
                    }
                    else if(s[i]=='B'){
                        sl+='G';
                    }
                    else{
                        sl+='R';
                    }
                }
                else{
                    if(s[i]=='R'){
                        if(s[i+1]=='B'){
                            sl+='G';
                        }
                        else{
                            sl+='B';
                        }
                    }
                    else if(s[i]=='G'){
                        if(s[i+1]=='B'){
                            sl+='R';
                        }
                        else{
                            sl+='B';
                        }
                    }
                    else{
                        if(s[i+1]=='G'){
                            sl+='R';
                        }
                        else{
                            sl+='G';
                        }
                    }
                }
            }
            else{
                if(s[i]=='R'){
                    sl+='B';
                }
                else if(s[i]=='B'){
                    sl+='G';
                }
                else{
                    sl+='R';
                }
            }
        }
        else{
            sl+=s[i];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]!=sl[i]){
            ans++;
        }
    }
    cout<<ans<<"\n";
    cout<<sl<<"\n";
}