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

int32_t main(){
    int w=1;
    //cin>>w;
    while(w--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<bool> vis(n+1,true);
        int a[26]={};
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            while(a[i]>0){
                int q=min(k,a[i]);
                a[i]-=q;
                k-=q;
                char c='a'+i;
                for(int i=0;i<n;i++){
                    if(vis[i] && s[i]==c){
                        vis[i]=false;
                        q--;
                    }
                    if(q==0){
                        break;
                    }
                }
                if(k==0){
                    break;
                }
            }
            if(k==0){
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]){
                cout<<s[i];
            }
        }
        cout<<"\n";
    }  
}