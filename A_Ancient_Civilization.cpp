#include <iostream>
#include <vector>
#include <algorithm>
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

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[100001][20];

vi in, out;
int tim = 0;

void dfs(int cur, int par, vi *adj)
{
	dp[cur][0] = par;
	in[cur] = (++tim);

	for (int i = 1; i < 20; ++i)
	{
		int two_i_minus_1 = dp[cur][i - 1];
		dp[cur][i] = dp[two_i_minus_1][i - 1];
	}

	for (int nb : adj[cur])
		if (nb != par)
			dfs(nb, cur, adj);


	out[cur] = (++tim);
}

bool is_first_anc_of_second(int u, int v)
{
	return in[u] < in[v] and out[u] > out[v];
}

int find_lca(int u, int v)
{
	if (is_first_anc_of_second(u, v))
		return u;

	if (is_first_anc_of_second(v, u))
		return v;
	
	for (int i = 19; i >= 0; --i)
		if (!is_first_anc_of_second(dp[u][i], v))
			u = dp[u][i];

	return dp[u][0];
}
void solve(){
    int n,l;
    cin>>n>>l;
    vector<int> a(l,0);
    int ans = 0;
    int t;
    for(int i=0;i<n;i++){
        int x = 0;
        cin>>t;
        while(t>0){
            if(t%2 == 1){
                a[x]++;
            }
            x++;
            t/=2;
        }
    }
    int k = 1;
    int kl;
    // for(int i =0;i<l;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    for(int i = 0;i<l;i++){
        kl = n - a[i];
        if(a[i] > kl){
            ans = ans + k;
        }
        k=k*2;
    }
    cout<<ans<<"\n";
}
int32_t main()
{
	int w;
    cin>>w;
    while (w--)
    {
        /* code */
        solve();
    }
}