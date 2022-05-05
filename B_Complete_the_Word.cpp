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


int32_t main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<vector<int>> dp(n+1,vi(27,0));
    if(n<26){
        cout<<-1;
    }
    else{
        bool bl=false;
        vector<int> ans(26,-1);
        int i1;
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                for(int j=0;j<26;j++){
                    dp[i+1][j]=dp[i][j];
                }
                dp[i+1][26]=dp[i][26]+1;
            }
            else{
                dp[i+1][26]=dp[i][26];
                for(int j=0;j<26;j++){
                    dp[i+1][j]=dp[i][j];
                }
                dp[i+1][s[i]-'A']++;
            }
            if(i>=25){
                int count=0;
                for(int j=0;j<26;j++){
                    if((dp[i+1][j]-dp[i-25][j])==1){
                        count++;
                    }
                }
                count+=(dp[i+1][26]-dp[i-25][26]);
                if(count==26){
                    bl=true;
                    i1=i;
                    break;
                }
            }
        }
        if(!bl){
            cout<<-1;
        }
        else{
            for(int i=0;i<(i1-25);i++){
                if(s[i]=='?'){
                    cout<<'A';
                }
                else{
                    cout<<s[i];
                }
            }
            vector<bool> vis(26);
            for(int i=i1-25;i<=i1;i++){
                if(s[i]!='?'){
                    ans[i-(i1-25)]=(s[i]-'A');
                    vis[s[i]-'A']=true;
                }
            }
            for(int i=0;i<26;i++){
                if(ans[i]==-1){
                    for(int j=0;j<26;j++){
                        if(!vis[j]){
                            ans[i]=j;
                            vis[j]=true;
                            break;
                        }
                    }
                }
            }
            for(int i=0;i<26;i++){
                cout<<(char)(ans[i]+'A');
            }
            for(int i=i1+1;i<(n);i++){
                if(s[i]=='?'){
                    cout<<'A';
                }
                else{
                    cout<<s[i];
                }
            }
        }
    }
    cout<<"\n";
}