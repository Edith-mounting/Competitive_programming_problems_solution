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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// C++ program to find prime factorization of a 
// number n in O(Log n) time with precomputation 
// allowed. 

#define MAXN 200001 

// stores smallest prime factor for every number 
int spf[MAXN]; 

// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
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
} 

// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<int> getFactorization(int x) 
{ 
	vector<int> ret; 
	while (x != 1) 
	{ 
		ret.push_back(spf[x]); 
		x = x / spf[x]; 
	} 
	return ret; 
} 
/*
// driver program for above function 
int main(int argc, char const *argv[]) 
{ 
	// precalculating Smallest Prime Factor 
	sieve(); 
	int x = 12246; 
	cout << "prime factorization for " << x << " : "; 

	// calling getFactorization function 
	vector <int> p = getFactorization(x); 

	for (int i=0; i<p.size(); i++) 
		cout << p[i] << " "; 
	cout << endl; 
	return 0; 
} */
int lcm(int a,int b){
	return (a*b)/__gcd(a,b);
}
int32_t main() 
{
    //sieve();
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0,pref=0;
	for(int i=0;i<n;i++){
		ans=__gcd(ans,lcm(pref,a[i]));
		pref=__gcd(pref,a[i]);
	}
    cout<<ans<<"\n";
}