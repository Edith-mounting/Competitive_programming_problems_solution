#include <iostream>
#include <algorithm>
#include <map>
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
string s;
bool ch(int a,int b,int i){
    int q=9-i;
    if(i%2==0){
        if(a>(b+ q/2+1)){
            return true;
        }
        if(b> (a+q/2)){
            return true;
        }
    }
    else{
        if(a> b+ q/2 ){
            return true;
        }
        if(b> a+q/2){
            return true;
        }
    }
    return false;
}
int f(int a,int b,int i){
    if(i==10){
        return 10;
    }
    if(s[i]=='?'){
        if(i%2==0){
            if(ch(a+1,b,i) || ch(a,b,i)){
                return i+1;
            }
            else{
                return min(f(a,b,i+1),f(a+1,b,i+1));
            }
        }
        else{
            if(ch(a,b+1,i) || ch(a,b,i)){
                return i+1;
            }
            else{
                return min(f(a,b,i+1), f(a,b+1,i+1));
            }
        }
    }
    else{
        if(s[i]=='0'){
            if(ch(a,b,i)){
                return i+1;
            }
            else{
                return f(a,b,i+1);
            }
        }
        else{
            if(i%2==0){
                a++;
            }
            else{
                b++;
            }
            if(ch(a,b,i)){
                return i+1;
            }
            else{
                return f(a,b,i+1);
            }
        }
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        cin>>s;
        int ans=f(0,0,0);
        cout<<ans<<"\n";
    }
}