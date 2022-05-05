#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
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
#define vip             vector<pair<int,double>>
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

void solve(){
	int n;
	cin>>n;
	int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack<vi> s;
    vi x;
    x.pb(a[0]);
    s.push(x);
    cout<<a[0]<<"\n";
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]+1){
            vi v=s.top();
            s.pop();
            vi vl;
            for(int j=0;j<v.size()-1;j++){
                vl.pb(v[j]);
                cout<<v[j]<<".";
            }
            cout<<a[i]<<"\n";
            vl.pb(a[i]);
            s.push(vl);
        }
        else if(a[i]==a[i-1]){
            if(a[i]==1){
                vi v=s.top();
                vi vl;
                for(int j=0;j<v.size();j++){
                    cout<<v[j]<<".";
                    vl.pb(v[j]);
                }
                cout<<a[i]<<"\n";
                vl.pb(a[i]);
                s.push(vl);
            }
            else{
                s.pop();
                vi v=s.top();
                s.pop();
                vi vl;
                for(int j=0;j<v.size()-1;j++){
                    vl.pb(v[j]);
                    cout<<v[j]<<".";
                }
                cout<<a[i]<<"\n";
                vl.pb(a[i]);
                s.push(vl);
            }
        }
        else{
            if(a[i]==1){
                vi v=s.top();
                vi vl;
                s.pop();
                for(int j=0;j<v.size();j++){
                    cout<<v[j]<<".";
                    vl.pb(v[j]);
                }
                cout<<a[i]<<"\n";
                vl.pb(a[i]);
                s.push(vl);
            }
            else{
                s.pop();
                vi v=s.top();
                s.pop();
                vi vl;
                for(int j=0;j<v.size()-1;j++){
                    vl.pb(v[j]);
                    cout<<v[j]<<".";
                }
                cout<<a[i]<<"\n";
                vl.pb(a[i]);
                s.push(vl);
            }
        }
    }
}
int32_t main()
{
	FIO;
	int w;
	cin>>w;
	while(w--){
		solve();
		cout<<"\n";
	}

}
