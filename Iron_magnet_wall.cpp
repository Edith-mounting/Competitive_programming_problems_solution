#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
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
#define mod             1000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int sheets[n];
        int pl=0;
        for(int i=0;i<n;i++){
            if(s[i]==':')pl++;

            sheets[i]=pl;
        }
        queue<int> mq;
        int counti=0;
        queue<int> iq;
        int p;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                if(mq.empty()){
                    iq.push(i);
                }
                else{
                    bool b=true;
                    while(!mq.empty()){
                        p=k+1-(i-mq.front())-(sheets[i]-sheets[mq.front()]);
                        if(p>0){
                            counti++;
                            b=false;
                            mq.pop();
                            break;
                        }
                        mq.pop();
                    }
                    if(b){
                        iq.push(i);
                    }
                }
            }
            else if(s[i]=='_'){
                continue;
            }
            else if(s[i]==':'){
                continue;
            }
            else if(s[i]=='X'){
                while(!mq.empty()){
                    mq.pop();
                }
                while(!iq.empty()){
                    iq.pop();
                }
            }
            else{
                if(!iq.empty()){
                    bool b=true;
                    while(!iq.empty()){
                        p=k+1-(i-iq.front())-(sheets[i]-sheets[iq.front()]);
                        if(p>0){
                            counti++;
                            b=false;
                            iq.pop();
                            break;
                        }
                        iq.pop();
                    }
                    if(b){
                        mq.push(i);
                    }
                }
                else{
                    mq.push(i);
                }
            }
        }
        cout<<counti<<"\n";
    }
}