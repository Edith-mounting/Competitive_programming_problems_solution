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

vector<int> a;
int n;
bool f(int index,int cur,int value){
    if(index==n){
        if(cur==value){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(f(index+1,cur+a[index],value) || f(index+1,cur,value) || f(index+1,cur-a[index],value)){
            return true;
        }
        else{
            return false;
        }
    }
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        cin>>n;
        bool bl=false;
        a.clear();
        a.resize(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<=0){
                bl=true;
            }
        }
        if(bl){
            cout<<"YES";
        }
        else{
            for(int i=0;i<n;i++){
                int q=a[i];
                a[i]=0;
                bl= bl|f(0,0,q);
                a[i]=q;
                if(bl){
                    break;
                }
            }
            if(bl){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
        }
        cout<<"\n";
    }
}