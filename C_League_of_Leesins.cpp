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
    //vector<bool> vis(n+1,false);
    //vector<bool> vis1(n-1,false);
    vi v[n+1];
    int kl=n-2;
    int a[kl][3];
    for(int i=0;i<n-2;i++){
        int x1,x2,x3;
        cin>>x1>>x2>>x3;
        v[x1].pb(i);
        v[x2].pb(i);
        v[x3].pb(i);
        a[i][0]=x1;
        a[i][1]=x2;
        a[i][2]=x3;
    }
    int x=0,x1=0,x2=0,prev;
    vi ans;
    for(int i=1;i<n+1;i++){
        if(v[i].size()==1){
            x=i;
            ans.pb(i);
            prev=v[i][0];
            int q1,q2,q3;
            q1=a[prev][0];
            q2=a[prev][1];
            q3=a[prev][2];
            if(q1==x){
                if(v[q2].size()==2){
                    x1=q2;
                    x2=q3;
                }
                else{
                    x2=q2;
                    x1=q3;
                }
            }
            else if(q2==x){
                if(v[q1].size()==2){
                    x1=q1;
                    x2=q3;
                }
                else{
                    x2=q1;
                    x1=q3;
                }
            }
            else{
                if(v[q2].size()==2){
                    x1=q2;
                    x2=q1;
                }
                else{
                    x1=q1;
                    x2=q2;
                }
            }
            ans.pb(x1);
            ans.pb(x2);
            break;
        }
    }
    //cout<<x1<<" "<<x2;
    for(int j=0;j<n-3;j++){
        map<int,int> mp;
        for(auto i:v[x1]){
            if(i!=prev){
                mp[i]++;
            }
        }
        for(auto i:v[x2]){
            if(i!=prev){
                mp[i]++;
            }
        }
        int i1;
        for(auto i:mp){
            if(i.ss==2){
                i1=i.ff;
                break;
            }
        }
        prev=i1;
        int q1=a[prev][0];
        int q2=a[prev][1];
        int q3=a[prev][2];
        if(q1!=x1 && q1!=x2){
            x1=x2;
            x2=q1;
        }
        else if(q2!=x1 && q2!=x2){
            x1=x2;
            x2=q2;
        }
        else{
            x1=x2;
            x2=q3;
        }
        ans.pb(x2);
        //cout<<x1<<" "<<x2<<"\n";
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}