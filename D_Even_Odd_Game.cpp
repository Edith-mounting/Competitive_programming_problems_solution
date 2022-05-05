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
int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        multiset<int> s1,s2;
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(a[i]&1){
                s2.insert(a[i]);
            }
            else{
                s1.insert(a[i]);
            }
        }
        //cout<<s1.size()<<" "<<s2.size()<<" ";
        int i=0;
        while(s1.size()>0 && s2.size()>0){
            if(i%2==0){
                //alice turn
                auto j=s1.end();
                auto k=s2.end();
                j--,k--;
                if((*j) >= (*k)){
                    x+=(*j);
                    s1.erase(j);
                }
                else{
                    s2.erase(k);
                }
            }
            else{
                auto j=s1.end();
                auto k=s2.end();
                j--,k--;
                if(*k >= *j){
                    y+=(*k);
                    s2.erase(k);
                }
                else{
                    s1.erase(j);
                }
            }
            i++;
        }
        while(s1.size()>0){
            if(i%2==0){
                auto j=s1.end();
                j--;
                x+=(*j);
                s1.erase(j);
            }
            else{
                auto j=s1.end();
                j--;
                s1.erase(j);
            }
            i++;
        }
        while(s2.size()>0){
            if(i%2==1){
                auto j=s2.end();
                j--;
                y+=(*j);
                s2.erase(j);
            }
            else{
                auto j=s2.end();
                j--;
                s2.erase(j);
            }
            i++;
            //cout<<"YES ";
        }
        //cout<<x<<" "<<y<<"\n";
        if(x>y){
            cout<<"Alice";
        }
        else if(x==y){
            cout<<"Tie";
        }
        else{
            cout<<"Bob";
        }
        cout<<"\n";
    }
}