#include <iostream>
#include <algorithm>
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
#define mod             998244353
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
int area(int x1,int y1,int x2,int y2){
    if(x2<0 || y2<0){
        return -1;
    }
    return absk(x1*y2-y1*x2);
}
int f(int a,int b,int k1,int k2){
    int ans=-1;
    int xmax,ymax;
    int check;
    if(k2+a+b == k1){
        check=area(a,b,a,k2+b);
        if(check>ans){
            ans=check;
            xmax=a;
            ymax=k2+b;
        }
        check=area(a,b,k2+a,b);
        if(check>ans){
            ans=check;
            xmax=k2+a;
            ymax=b;
        }
    }
    else{
        check=area(a,b,a-k2,b);
        if(check>ans){
            ans=check;
            xmax=a-k2;
            ymax=b;
        }
        check=area(a,b,a,b-k2);
        if(check>ans){
            ans=check;
            xmax=a;
            ymax=b-k2;
        }
    }
    if((k1+k2+a-b)%2==0){
        check=area(a,b,(k1+k2+a-b)/2,(k1-k2-a+b)/2);
        if(check>ans){
            ans=check;
            xmax=(k1+k2+a-b)/2;
            ymax=(k1-k2-a+b)/2;
        }
    }
    if((k1-k2+a-b)%2==0){
        check=area(a,b,(k1-k2+a-b)/2,(k1+k2+b-a)/2);
        if(check>ans){
            ans=check;
            xmax=(k1-k2+a-b)/2;
            ymax=(k1+k2-a+b)/2;
        }
    }
    return ans;
}
pair<int,int> final(int a,int b,int k1,int k2){
    int ans=-1;
    int xmax,ymax;
    int check;
    if(k2+a+b == k1){
        check=area(a,b,a,k2+b);
        if(check>ans){
            ans=check;
            xmax=a;
            ymax=k2+b;
        }
        check=area(a,b,k2+a,b);
        if(check>ans){
            ans=check;
            xmax=k2+a;
            ymax=b;
        }
    }
    else{
        check=area(a,b,a-k2,b);
        if(check>ans){
            ans=check;
            xmax=a-k2;
            ymax=b;
        }
        check=area(a,b,a,b-k2);
        if(check>ans){
            ans=check;
            xmax=a;
            ymax=b-k2;
        }
    }
    if((k1+k2+a-b)%2==0){
        check=area(a,b,(k1+k2+a-b)/2,(k1-k2-a+b)/2);
        if(check>ans){
            ans=check;
            xmax=(k1+k2+a-b)/2;
            ymax=(k1-k2-a+b)/2;
        }
    }
    if((k1-k2+a-b)%2==0){
        check=area(a,b,(k1-k2+a-b)/2,(k1+k2+b-a)/2);
        if(check>ans){
            ans=check;
            xmax=(k1-k2+a-b)/2;
            ymax=(k1+k2-a+b)/2;
        }
    }
    return {xmax,ymax};
}
void solve(){
    int d1,d2,d3;
    cin>>d1>>d2>>d3;
    if((d1+d2+d3)%2==1){
        cout<<"NO\n";
        return ;
    }
    bool bl=true;
    if(d1+d2<d3){
        bl=false;
    }
    if(d1+d3<d2){
        bl=false;
    }
    if(d2+d3<d1){
        bl=false;
    }
    if(!bl){
        cout<<"NO\n";
        return ;
    }
    cout<<"YES\n";
    int l=0,r=d1+1;
    int mid;
    int ans;
    while(l<r){
        mid=(l+r)/2;
        //check for mid,mid+1,mid-1
        int q1=f(mid,d1-mid,d3,d2);
        int q2=f(mid+1,d1-mid-1,d3,d2);
        int q3=f(mid-1,d1-mid+1,d3,d2);
        if(q1>=q3){
            l = mid+1;
        }

        if(q1>=q2){
            r = mid;
        }
    }
    int x1=l-1;
    int y1=d1-x1;
    cout<<1<<" "<<1<<"\n";
    pii p3=final(x1,y1,d3,d2);
    cout<<x1+1<<" "<<y1+1<<"\n";
    cout<<p3.ff+1<<" "<<p3.ss+1<<"\n";
}
int32_t main(){
    int w=1;
    cin>>w;
    while(w--){
        solve();
    }
}