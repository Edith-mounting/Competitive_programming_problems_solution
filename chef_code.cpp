#include<iostream>
#include <algorithm>
#include <string>
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

// C++ program to print all possible
// substrings of a given string

// Function to print all sub strings
set<string> subString(string s, int n) 
{
	// Pick starting point in outer loop
	// and lengths of different strings for
	// a given starting point
    set<string> sl;
	for (int i = 0; i < n; i++) 
		for (int len = 1; len <= n - i; len++)
			sl.insert(s.substr(i, len));

    return sl;        
}

// Driver program to test above function
int32_t main() 
{
	
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        set<string> sl=subString(s,s.length());
        vector<string> v;
        //for(auto i:sl){
          //  cout<<i<<"\n";
        //}
        for(auto i:sl){
            v.pb(i);
        }
        int x=v.size(),ans=0;
        string skl,spl;
        for(int i=0;i<x;i++){
            spl=v[i];
            int kl=0;
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]=='1'){
                    kl++;
                }
            }
            if(kl%2==0){
                reverse(v[i].begin(),v[i].end());
                string skl=v[i];
                if(skl!=spl){
                    for(auto i:sl){
                        if(i==skl){
                            ans++;
                            //cout<<skl<<"\n";
                        }
                    }
                }
            }
        }
        cout<<sl.size()-(ans/2)<<"\n";
    }
}

