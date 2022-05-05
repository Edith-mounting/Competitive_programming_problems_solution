#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define int long long
#define mod 1000000007
string countIslands(string a, string b)
{
	int n = a.length();
	int m = b.length();
	unordered_map<char,int> m1, m2;
	for(int i = 0; i < n; i++){
		m1[a[i]]++;
	}
	for(int i = 0; i < m; i++){
		m2[b[i]]++;
	}
    for(auto i:m2){
		if(i.second > m1[i.first]){
			return "false";
		}
	}
	return "true";
}
void solve(int n){
	int sum = (n*(n + 1))/2;
	if(sum%2 == 1){
		cout << 0;
		return ;
	}
	sum/=2;
	vector<int> dp(sum + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		if(i > sum){
			break;
		}
		for(int j = sum; j >= 0; j--){
			if( j - i >= 0){
				dp[j] = (dp[j] + dp[j - i])%mod;
			}
		}
	}
	dp[sum]/=2;
	cout << dp[sum];
}
// main function
int32_t main()
{
    int n;
	cin >> n;
	solve(n);
}
