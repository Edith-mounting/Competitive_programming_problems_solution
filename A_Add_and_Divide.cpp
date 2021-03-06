#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define int             long long
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
//#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main()
{
    int w;
    cin >> w;
    while(w--)
    {
        int a,b;
        cin >> a >> b;
        int counti = 0;
        if(b==1)
        {
            counti++;
            b++;
        }

        int mi = a+2;
        int q = 0;
        while(q<=mi)
        {
            q = counti;
            int m = a;
            while(m>0)
            {
                m = m/b;
                q++;
            }
            counti++;
            b++;
            mi = min(mi, q);
        }

        cout << mi << '\n';

    }
}