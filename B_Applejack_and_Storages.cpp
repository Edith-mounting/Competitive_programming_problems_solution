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

int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int N=100000+1;
    vector<int> v(N,0);
    for(int i=0;i<n;i++){
        v[a[i]]++;
    }
    int count4=0,count2=0;
    for(int i=0;i<N;i++){
        count4+=v[i]/4;
        count2+=v[i]/2;
    }
    int q;
    cin>>q;
    while(q--){
        char kl;
        int x;
        cin>>kl>>x;
        if(kl=='+'){
            v[x]++;
            if(v[x]%4==0){
                count4++;
            }
            if(v[x]%2==0){
                count2++;
            }
        }
        else{
            v[x]--;
            if(v[x]%4==3){
                count4--;
            }
            if(v[x]%2==1){
                count2--;
            }
        }
        if(count4<1){
            cout<<"NO";
        }
        else if(count4==1){
            if(count2>=4){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
        }
        else{
            cout<<"YES";
        }
        cout<<"\n";
    }
}