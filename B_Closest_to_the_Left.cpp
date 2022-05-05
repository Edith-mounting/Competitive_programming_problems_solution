#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
//#include <bits/stdc++.h>
#include <queue> 
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
vector<int> a;
int binarysearch(int k,int n){
    int l=0,r=n-1;
    int mid=(l+r)/2;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]<=k){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return mid;
}
int32_t main(){
    int n,k;
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    while(k--){
        int p;
        cin>>p;
        int ans=binarysearch(p,n);
    }
}