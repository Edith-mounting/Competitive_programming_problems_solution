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
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        vector<bool> v(n+1,false);
        vi ans1(n);
        ans1[0]=a[0];
        v[a[0]]=true;
        int i1=1;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                while(v[i1]){
                    i1++;
                }
                v[i1]=true;
                ans1[i]=i1;
            }
            else{
                v[a[i]]=true;
                ans1[i]=a[i];
            }
        }
        for(auto i:ans1){
            cout<<i<<" ";
        }
        cout<<"\n";
        v.clear();
        v.resize(n+1,false);
        vi ans2(n);
        ans2[0]=a[0];
        v[a[0]]=true;
        i1=0;
        set<int> s;
        for(int i=i1+1;i<a[0];i++){
            s.insert(i);
        }
        i1=a[0];
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                int k=*s.rbegin();
                ans2[i]=k;
                s.erase(k);
                v[k]=true;
            }
            else{
                v[a[i]]=true;
                ans2[i]=a[i];
                for(int j=i1+1;j<a[i];j++){
                    if(!v[j]){
                        s.insert(j);
                    }
                }
                i1=a[i];
            }
        }
        for(auto i:ans2){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}