#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <iomanip>
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
#define mod             998244353
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
int powd(int x,int y){
    if(y==0){
        return 1;
    }
    else if(y%2==0){
        int t=powd(x,y/2);
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2);
        return (((t*t)%mod)*x)%mod;
    }
}
struct help{
    int x1,x2,index;
};
bool comp(help a,help b){
    if(a.x1!=b.x1){
        return a.x1<b.x1;
    }
    else{
        return b.x2<a.x2;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    char a[n][m];
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='A'){
                count++;
            }
        }
    }
    if(count==0){
        cout<<"MORTAL";
        return ;
    }
    if(count==n*m){
        cout<<0;
        return ;
    }
    int count1=0,count2=0;
    for(int j=0;j<m;j++){
        if(a[0][j]=='A'){
            count1++;
        }
        if(a[n-1][j]=='A'){
            count2++;
        }
    }
    if(count1==m){
        cout<<1;
        return;
    }
    if(count2==m){
        cout<<1;
        return ;
    }
    count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(a[i][0]=='A'){
            count1++;
        }
        if(a[i][m-1]=='A'){
            count2++;
        }
    }
    if(count1==n){
        cout<<1;
        return;
    }
    if(count2==n){
        cout<<1;
        return ;
    }
    if(a[0][m-1]=='A'){
        cout<<2;
        return;
    }
    else if(a[0][0]=='A'){
        cout<<2;
        return;
    }
    else if(a[n-1][0]=='A'){
        cout<<2;
        return;
    }
    else if(a[n-1][m-1]=='A'){
        cout<<2;
        return;
    }
    vector<int> row(n,0);
    vi col(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='A'){
                row[i]++;
                col[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(row[i]==m){
            cout<<2;
            return ;
        }
    }
    for(int i=0;i<m;i++){
        if(col[i]==n){
            cout<<2;
            return ;
        }
    }
    for(int j=0;j<m;j++){
        if(a[0][j]=='A'){
            cout<<3;
            return;
        }
        if(a[n-1][j]=='A'){
            cout<<3;
            return;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i][0]=='A'){
            cout<<3;
            return;
        }
        if(a[i][m-1]=='A'){
            cout<<3;
            return;
        }
    }
    cout<<4;
}
int32_t main()
{
	FIO;
	int w=1;
	cin>>w;
	while(w--){
		solve();
        cout<<"\n";
	}

}
