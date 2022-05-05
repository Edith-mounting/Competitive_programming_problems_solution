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
#define range(a,b)        substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x)         cerr<<#x<<": "<<x<<" "<<endl;
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
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        string s,t;
        cin>>s>>t;
        bool b = false;
        int m=t.length();
        for(int i=0;i<s.length() && !b;i++){
            if(t[0]==s[i]){
                int k=i,j=1;
                while(!b && j<t.length()){

                    if(k>0){
                        if(t[j]==s[k-1]){
                            
                            int p=j;
                                for(int q=k-1;q>=0 && p<t.length();q--){
                                    if(s[q]!=t[p]){
                                        break;
                                    }
                                    else{
                                        p++;
                                    }
                                }
                                if(p==t.length()){
                                    b=true;
                                    break;
                                }
                            
                        }
                    }

                    if(k==s.length()-1){
                        break;
                    }
                    
                    if(t[j]==s[k+1]){
                        j++;
                        k++;
                    }
                    else{
                        break;
                    }
                    
                }

                if(j==t.length()){
                    b = true;
                }
            }
  
        }
        if(b){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}