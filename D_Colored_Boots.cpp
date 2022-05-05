#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue> 
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

int32_t main(){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    set<int> a[26];
    set<int> question;
    for(int i=0;i<n;i++){
        if(s1[i]!='?'){
            a[s1[i]-'a'].insert(i+1);
        }
        else{
            question.insert(i+1);
        }
    }
    set<int>::iterator it;
    vector<pii> ans;
    vector<int> k1;
    vector<bool> v(n+1,false);
    v[0]=true;
    vi alpha;
    for(int i=0;i<n;i++){
        if(s2[i]!='?'){
            if(a[s2[i]-'a'].size()>0){
                it=a[s2[i]-'a'].begin();
                ans.pb({*it,i+1});
                v[*it]=true;
                //cout<<*it<<" "<<i+1<<"\n";
                a[s2[i]-'a'].erase(*it);
            }
            else{
                if(question.size()>0){
                    it=question.begin();
                    ans.pb({*it,i+1});
                    v[*it]=true;
                    question.erase(*it);
                }
            }
        }
        else{
            alpha.pb(i+1);
        }
    }
    int j=0;
    for(int i=1;i<n+1;i++){
        if(!v[i]){
            if(j<alpha.size()){
                ans.pb({i,alpha[j]});
                j++;
            }
        }
    }
    
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.ff<<" "<<i.ss<<"\n";
    }
}