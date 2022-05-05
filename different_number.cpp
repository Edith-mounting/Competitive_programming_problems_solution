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
    string s;
    cin>>s;
    int ans=0;
    set<string> st;
    bool b=false;
    string sl="";
    for(int i=0;i<s.length();i++){
        if((int)s[i]<58){
            b=true;
            sl+=s[i];
        }
        else{
            if(b){
                int q=-1;
                for(int j=0;j<sl.length();j++){
                    if(sl[j]=='0'){
                        q++;
                    }
                    else{
                        break;
                    }
                }
                string a="";
                for(int j=q+1;j<sl.length();j++){
                    a+=sl[j];
                }
                st.insert(a);
            }
            sl="";
            b=false;
        }
    }
    if(b){
        int q=-1;
        for(int j=0;j<sl.length();j++){
            if(sl[j]=='0'){
                q++;
            }
            else{
                break;
            }
        }
        string a="";
        for(int j=q+1;j<sl.length();j++){
            a+=sl[j];
        }
        st.insert(a);
    }
    cout<<st.size()<<"\n";
}