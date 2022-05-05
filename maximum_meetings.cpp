#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
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
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    if(y%2==0){
        int t=powd(x,y/2);
        return (t*t);
    }
    else{
        int t=powd(x,y/2);
        return (t*t*x);
    }
}
struct meet{
    int finish,start,i1;
};
bool comp(meet x,meet y){
    return x.finish<y.finish;
}
int32_t main(){
    int n;
    cin>>n;
    vector<meet> v(n);
    for(int i=0;i<n;i++){
        int x;
        cin>> x;
        v[i].start= x;
        v[i].i1= i+1;
    }
    for(int i=0;i<n;i++){
        int y;
        cin>> y;
        v[i].finish= y;
    }
    sort(v.begin(),v.end(),comp);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i].finish<<" "<<v[i].start<<" "<<v[i].i1<<"\n";
    // }
    vector<int > ans;
    ans.push_back(v[0].i1);
    for(int i=1;i<n;i++){
        if(v[i].start>=v[ans[ans.size()-1]-1].finish){
            ans.push_back(v[i].i1);
        }
    }
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}