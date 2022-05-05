#include <iostream>
#include <algorithm>
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
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
void solve(){
	int n;
    cin>>n;
    string s;
    cin>>s;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(s[i]=='D'){
            q.push(1);
        }
        else q.push(-1);
    }
    string ans="";
    int count=0;
    while(1){
        int sz=q.size();
        queue<int> temp;
        while(!q.empty()){
            int x=q.front();
            //cout<<x<<" ";
            q.pop();
            if(x==1){
                if(count>=0){
                    temp.push(x);
                }
                count++;
            }
            else{
                if(count<=0){
                    temp.push(x);
                }
                count--;
            }
        }
        //cout<<"\n";
        bool b1=false,b2=false;
        while(!temp.empty()){
            if(temp.front()==-1){
                b1=true;
            }
            if(temp.front()==1){
                b2=true;
            }
            q.push(temp.front());
            temp.pop();
        }
        if(b1 && b2){
            continue;
        }
        else{
            if(b1){
                ans="R";
            }
            if(b2){
                ans="D";
            }
            break;
        }
    }
    cout<<ans;
}
int32_t main()
{
	FIO;
	int w=1;
	//cin>>w;
	while(w--){
		solve();
		cout<<"\n";
	}

}
