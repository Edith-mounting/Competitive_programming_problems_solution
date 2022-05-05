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
#define MAXN   1000000
int spf[MAXN];
int32_t main(){
    int w,wl;
    //cin>>w;
    wl=w;
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
  
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
  
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
  
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
  
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
    //while(w--){
        int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {

		int n;
		cin >> n;
		vector<long long> d(n);
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}
		sort(d.begin(), d.end());
		long long x = d[0] * d[n - 1];
		
		vector<long long> dd;
		for (int i = 2; i * 1ll * i <= x; ++i) {
			if (x % i == 0) {
				dd.push_back(i);
				if (i != x / i) {
					dd.push_back(x / i);
				}
			}
		}
		sort(dd.begin(), dd.end());
		
		if (dd == d) {
			cout << x << endl;
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}