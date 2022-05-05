#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vb              vector<bool>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int absk(int x){
    if(x<0){
        return -x;
    }
    return x;
}

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        int n=s.length();
        bool bl=true;
        int count1=0;
        for(int i=0;i< (n/2 + n%2);i++){
            if(s[i]=='?'){
                if(s[n-i-1]=='?'){
                    count1+=2;
                    if(n%2==1){
                        if(i==n/2 + 1){
                            count1--;
                        }
                    }
                }
                else{
                    s[i]=s[n-i-1];
                }
            }
            else{
                if(s[i]!=s[n-i-1]){
                    bl=false;
                    break;
                }
            }
        }
        if(!bl){
            cout<<-1<<"\n";
            continue;
        }
        int x1=0,x2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')x1++;
            else if(s[i]=='1')x2++;
        }
        int q1=0,q2=0;
        if(x1<a){
            if((a-x1)%2==0){
                q1+=(a-x1);
            }
        }
        if(x2<b){
            if((b-x2)%2==0){
                q2+=(a-x2);
            }
        }
        if(q1+q2==count1){
            if(n%2==1){
                if(s[n/2]=='?'){
                    if(q1%2==1){
                        q1--;
                        s[n/2]='0';
                    }
                    else{   
                        q2--;
                        s[n/2]='1';
                    }
                }
            }
            for(int i=0;i<n/2;i++){
                if(s[i]=='?'){
                    if(q1>0){
                        q1-=2;
                        s[i]='0';
                        s[n-i-1]='0';
                    }
                    else{
                        q2-=2;
                        s[i]='1';
                        s[n-i-1]='1';
                    }
                }
            }
            cout<<s<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
}