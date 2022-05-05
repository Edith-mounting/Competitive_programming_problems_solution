#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
//#include <bits/stdc++.h>
#include <map> 
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
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
const double pi = acos(-1);
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
    else if(y%2==0){
        int t=powd(x,y/2)%mod;
        return (t*t)%mod;
    }
    else{
        int t=powd(x,y/2)%mod;
        return (((t*t)%mod)*x)%mod;
    }
}
int32_t main(){
    string s;
    cin>>s;
    vi v1;
    vi zero;
    vi a(7);
    string s1="1869";
    do{
        int k=0;
        for(int i=0;i<4;i++){
            k=k*10 +(s1[i]-'0');
        }
        a[k%7]=k;
    }while(next_permutation(s1.begin(),s1.end()));
    
    int v[10]={};
    for(int i=0;i<s.length();i++){
        v[s[i]-'0']++;
    }
    v[1]--,v[6]--,v[8]--,v[9]--;
    for(int i=1;i<10;i++){
        while(v[i]>0){
            v1.pb(i);
            v[i]--;
        }
    }
    int remainder=0;
    for(int i=0;i<v1.size();i++){
        remainder=(v1[i]+remainder*10)%7;
    }
    for(int i:v1){
        cout<<i;
    }
    for(int i=0;i<7;i++){
        string s2=to_string(a[i]);
        int m1=remainder;
        for(int j=0;j<4;j++){
            m1=(m1*10 +(s2[j]-'0'))%7;
        }
        if(m1==0){
            cout<<s2;
            break;
        }
    }
    for(int i=0;i<v[0];i++){
        cout<<0;
    }
    
}