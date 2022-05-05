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
    cin >> w;
    while(w--)
    {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> a(n+1, 0);
        vector<int> b(n+1, 0);
        int q1 = 1;
        int q2 = 1;
        bool bl=true;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                bl=false;
                break;
            }
        }
        if(bl){
            cout<<0<<"\n";
            continue;
        }
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='1')
            {
                if(q1<=q2)
                {
                    q2 = q1+1;
                    a[i] = 0;
                }else
                {
                    q2++;
                    a[i] = 1;
                }
                b[i] = 0;
            }else
            {
                if(q1<=q2)
                {
                    q1++;
                    b[i] = 0;
                }else
                {
                    q1 = q2+1;
                    b[i] = 1;
                }

                a[i] = 1;
            }
        }
        int p = 1;
        for(int i=0; i<n; i++)
        {
            if((s[i]-'0')==p)
            {
                cout << p;
            }
            if(p==1)
            {
                p = a[i];
            }else
            {
                p = b[i];
            }
        }
        cout << p << '\n';
    }
}