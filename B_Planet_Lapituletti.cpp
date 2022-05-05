#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int ans1,ans2;
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
vi inverse(101,-1);
int h,m;
bool check(int k){
    if(k==0 || k==1 || k==2 || k==5 || k==8){
        return true;
    }
    else{
        return false;
    }
}
bool valid(int i,int j){
    if(inverse[i]!=-1 && inverse[j]!=-1){
        if(inverse[j]<h && inverse[i]<=m){
            return true;
        }
    }
    return false;
}
int32_t main() 
{
    for(int i=1;i<101;i++){
        int kl=i%10;
        int pl=(i/10)%10;
        if(check(i%10)&&check(pl)){
            if(kl==5){
                kl=2;
            }
            else if(kl==2){
                kl=5;
            }
            if(pl==5){
                pl=2;
            }
            else if(pl==2){
                pl=5;
            }
            inverse[i]=kl*10+pl;
        }
    }
    int w;
    cin>>w;
    while(w--){
        cin>>h>>m;
        ans1=0,ans2=0;
        int p,q;
        char c;
        cin>>p>>c>>q;
        bool b=false;
        for(int i=p;i<h;i++){
            for(int j=q;j<m;j++){
                if(valid(i,j)){
                    b=true;
                    ans1=i,ans2=j;
                    break;
                }
            }
            if(b){
                break;
            }
        }
        cout<<(ans1/10)<<ans1%10<<":"<<ans2/10<<ans2%10;
        cout<<"\n";
    }
}